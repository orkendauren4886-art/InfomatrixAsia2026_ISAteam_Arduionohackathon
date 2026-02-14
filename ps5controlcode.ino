#include <ps5Controller.h>
#include <ESP32Servo.h>

int frontLeftA  = 12;
int frontLeftB  = 13;

int frontRightA = 26;
int frontRightB = 14;

int backLeftA   = 32;
int backLeftB   = 33;

int backRightA  = 27;
int backRightB  = 25;

char MAC_ADRES[] = "4C:B9:9B:9D:29:F9";

int DEADZONE = 60;

float SPEED_FAST   = 2.0;
float SPEED_NORMAL = 1.2;
float SPEED_SLOW   = 0.6;
float speedMul     = 1.2;

int HIT_SPEED = 255;
int HIT_TIME  = 150;

Servo kicker;

bool hitActive = false;
unsigned long hitStart = 0;
int hitDir = 0;

void motor(int a, int b, int s){
  s = constrain(s, -255, 255);
  if(s > 0){
    analogWrite(a, s);
    analogWrite(b, 0);
  }else{
    analogWrite(a, 0);
    analogWrite(b, -s);
  }
}

void stopAll(){
  motor(frontLeftA,  frontLeftB,  0);
  motor(frontRightA, frontRightB, 0);
  motor(backLeftA,   backLeftB,   0);
  motor(backRightA,  backRightB,  0);
}

int deadzone(int v){
  return abs(v) < DEADZONE ? 0 : v;
}

void setup(){
  Serial.begin(115200);

  pinMode(frontLeftA, OUTPUT);
  pinMode(frontLeftB, OUTPUT);
  pinMode(frontRightA, OUTPUT);
  pinMode(frontRightB, OUTPUT);
  pinMode(backLeftA, OUTPUT);
  pinMode(backLeftB, OUTPUT);
  pinMode(backRightA, OUTPUT);
  pinMode(backRightB, OUTPUT);

  kicker.attach(4);
  kicker.write(30);

  ps5.begin(MAC_ADRES);
}

void loop(){
  if(!ps5.isConnected()){
    stopAll();
    return;
  }

  if(ps5.Triangle()) speedMul = SPEED_FAST;
  if(ps5.Circle())   speedMul = SPEED_NORMAL;
  if(ps5.Square())   speedMul = SPEED_SLOW;

  if(!hitActive){
    if(ps5.R1()){
      hitActive = true;
      hitStart = millis();
      hitDir = -1;
    }
    if(ps5.L1()){
      hitActive = true;
      hitStart = millis();
      hitDir = 1;
    }
  }

  if(hitActive){
    int p = hitDir * HIT_SPEED;

    motor(frontLeftA,  frontLeftB,  p);
    motor(backLeftA,   backLeftB,   p);
    motor(frontRightA, frontRightB, -p);
    motor(backRightA,  backRightB,  -p);

    if(millis() - hitStart >= HIT_TIME){
      hitActive = false;
      stopAll();
    }
    return;
  }

  if(ps5.Cross())  kicker.write(30);
  if(ps5.Square()) kicker.write(120);

  int Y = deadzone(-ps5.LStickY()) * speedMul;
  int X = deadzone(-ps5.LStickX()) * speedMul;
  int W = deadzone(-ps5.RStickX()) * speedMul;

  motor(frontLeftA,  frontLeftB,  Y + X + W);
  motor(frontRightA, frontRightB, Y - X - W);
  motor(backLeftA,   backLeftB,   Y - X + W);
  motor(backRightA,  backRightB,  Y + X - W);
}