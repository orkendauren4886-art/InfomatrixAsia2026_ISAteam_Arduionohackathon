# <span style="color:darkblue">Arduino Hackathon: Robot Football – ESP32 Robots</span>

This repository contains code and instructions for **two football robots** built for the Arduino Hackathon.  
We have **two robots**:  

- **Defender – defensive role**  
- **Player – offensive role**  

---

## <span style="color:darkgreen">Defender Robot</span>

**Defender Robot – protects goal area and blocks opponent**

![WhatsApp Image 2026-02-14 at 19 09 18](https://github.com/user-attachments/assets/7dcd41bb-a0af-477d-b9e6-9246fc3cdcc3)
![WhatsApp Image 2026-02-14 at 19 05 09](https://github.com/user-attachments/assets/bd32ba4d-206b-4737-bfd1-72e60fd7d5f7)


---

## <span style="color:darkred">Player Robot</span>

**Player Robot – attacks and moves the ball forward**
![WhatsApp Image 2026-02-14 at 19 10 46](https://github.com/user-attachments/assets/a995facf-22b0-406f-b087-9fcea0197945)
<img width="738" height="1000" alt="image" src="https://github.com/user-attachments/assets/7c9ba2ca-e514-4563-9853-393a1ba4b941" />



---

## <span style="color:darkorange">Settings Panel</span>

Both robots include a **settings panel** where you can adjust all key parameters:  

- **Max Speed** — maximum movement speed  
- **Max Yaw** — maximum rotation speed  
- **Deadzone** — joystick dead zone  
- **Expo** — smooth control near center  
- **Min PWM** — minimum motor power to start movement  
- **Mix Mode** — two mixing modes (Standard / Alt)  
- **Invert Axes** — invert control directions  
- **Motor Reverse** — reverse each motor’s direction  
- **Motor Pins** — change motor pins (safe pins only)  
- **Test Motors / Test Selected** — test motors individually  
- **Reset Defaults** — restore default settings  

This allows full customization without editing the code.

---

## <span style="color:purple">Code 1 – `ps5controlcode.ino` (Bluetooth)</span>

- Connects the robot to a **PS5 controller**  
- Controls 4 motors (holonomic/mecanum drive)  
- Movement: forward/backward, sideways, rotation  
- Supports speed modes, “hit” move, and kicker servo  

**Library:** [PS5 Controller Library](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa0JrQ0NicDhZT1hUcU5IbkpjQ0NocVJQY2thZ3xBQ3Jtc0tsNFhZc29keTZnREV4Y2lObDAtUW9BektIblVSZ3hyck5RZmZDd1Buc0I4cU5YSXZGR0Q4bDRmTHJBM3hzNXI5N0dlYzFIWExHQWxtSy12aHVjSFlxSUJVQ1UzUGFKbkJ1Sk5QTXpHMU10OHh5WVRDZw&q=https%3A%2F%2Fgithub.com%2Frodneybakiskan%2Fps5-esp32%2Farchive%2Frefs%2Fheads%2Fmain.zip&v=-ob3iKbw2jM)

### How to Use `ps5controlcode.ino`

1. Open `ps5controlcode.ino` in Arduino IDE  
2. Upload to ESP32  
3. Power on the ESP32  
4. Turn on PS5 controller and **press PS button** to connect  
5. Start controlling the robot  

---

## <span style="color:teal">Code 2 – `esp32_phonecontrolviawifi.ino` (WiFi)</span>

- ESP32 creates a **WiFi access point**  
- Hosts a control webpage with two joysticks and the **settings panel**  
- Left joystick – move forward/backward and sideways  
- Right joystick – rotate (yaw)  
- Settings panel allows changing all robot parameters (see above)  

### How to Use `esp32_phonecontrolviawifi.ino`

1. Open `esp32_phonecontrolviawifi.ino` in Arduino IDE  
2. Install **Gyver Settings** library  
3. Upload to ESP32  
4. Power on ESP32  
5. Connect to WiFi:  
   - SSID: **ESP32_CAR**  
   - Password: **12345678**  
6. Open in browser: `http://192.168.4.1`  
7. Adjust settings if needed and control the robot via webpage  

---

## <span style="color:brown">Hardware Notes</span>

- Motors require a **separate power supply**  
- Connect motor GND to ESP32 GND  
- Ensure motor pins are unique and correct  

---

## <span style="color:darkblue">Summary</span>

This repo contains everything needed to run **two robots** for Arduino Hackathon football matches:  

1. **Defender Robot** – blocking and defense code  
2. **Player Robot** – attacking code  
3. Two connection options: **`ps5controlcode.ino` (Bluetooth)** and **`esp32_phonecontrolviawifi.ino` (WiFi)**  
4. Full **settings panel** to adjust all robot parameters  

Both robots are ready to assemble, configure, and test.
