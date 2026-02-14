esp 32_phonecontrolviawifi.ino
you need to open it in arduino Ide and
download settings Gyver library

ESP32 launches a Wi-Fi access point and a control page.
The page has two joysticks and a settings panel.

How to Connect

Power on the ESP32.

Connect to Wi-Fi:

SSID: ESP32_CAR

Password: 12345678

Open in your browser: http://192.168.4.1

Controls

Left joystick: forward/backward and sideways movement.

Right joystick: rotation (yaw).

The joysticks automatically return to center.

Settings (Settings button)

Max Speed — maximum movement speed.

Max Yaw — maximum rotation speed.

Deadzone — joystick dead zone.

Expo — smoother control near the center.

Min PWM — minimum power required for motors to start moving.

Mix Mode — 2 mixing modes (Standard / Alt).

Invert Axes — invert control directions.

Motor Reverse — reverse direction of each motor.

Motor Pins — change motor pins (safe pins only).

Test Motors / Test Selected — motor testing.

Reset Defaults — reset settings to default.

If Something Doesn’t Move

Check motor direction (Motor Reverse).

Check motor pins and make sure they are unique.

Try changing Invert Axes.

Important About Power

Motors require a separate power supply!
The motor GND and ESP32 GND must be connected together.

Done. You can assemble and test.

ps5controlcode.ino 


