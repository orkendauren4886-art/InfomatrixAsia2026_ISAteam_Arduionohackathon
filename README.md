Arduino Hackathon: Robot Football – ESP32 Robots

This repository contains code and instructions for two football robots built for the Arduino Hackathon.
We have two robots:

Defender – defensive role

Player – offensive role

Each robot is based on ESP32 (38-pin) and can be controlled via WiFi or Bluetooth.

Robot Overview

Defender Robot – protects goal area and blocks opponent
![WhatsApp Image 2026-02-14 at 19 09 18](https://github.com/user-attachments/assets/eb13df8b-76a9-4b9c-99ef-1f47e0e4417e)
![WhatsApp Image 2026-02-14 at 19 05 09](https://github.com/user-attachments/assets/7f6a3da1-2e44-44e5-a084-954ac8c244d0)

Player Robot – attacks and moves the ball forward
<img width="738" height="1600" alt="image" src="https://github.com/user-attachments/assets/a49cf393-6d8b-4425-afc8-a28fdb669853" />
<img width="534" height="336" alt="image" src="https://github.com/user-attachments/assets/dfc09946-7695-4a87-82b6-383613625bc2" />


Settings Panel

Both robots include a settings panel where you can adjust all key parameters:

Max Speed — maximum movement speed

Max Yaw — maximum rotation speed

Deadzone — joystick dead zone

Expo — smooth control near center

Min PWM — minimum motor power to start movement

Mix Mode — two mixing modes (Standard / Alt)

Invert Axes — invert control directions

Motor Reverse — reverse each motor’s direction

Motor Pins — change motor pins (safe pins only)

Test Motors / Test Selected — test motors individually

Reset Defaults — restore default settings

This allows full customization without editing the code.

Code 1 – ps5controlcode.ino (Bluetooth)

Connects the robot to a PS5 controller

Controls 4 motors (holonomic/mecanum drive)

Movement: forward/backward, sideways, rotation

Supports speed modes, “hit” move, and kicker servo

How to Use ps5controlcode.ino

Open ps5controlcode.ino in Arduino IDE

Upload to ESP32

Power on the ESP32

Turn on PS5 controller and press PS button to connect

Start controlling the robot

Code 2 – esp32_phonecontrolviawifi.ino (WiFi)

ESP32 creates a WiFi access point

Hosts a control webpage with two joysticks and the settings panel

Left joystick – move forward/backward and sideways

Right joystick – rotate (yaw)

Settings panel allows changing all robot parameters (see above)

How to Use esp32_phonecontrolviawifi.ino

Open esp32_phonecontrolviawifi.ino in Arduino IDE

Install Gyver Settings library

Upload to ESP32

Power on ESP32

Connect to WiFi:

SSID: ESP32_CAR

Password: 12345678

Open in browser: http://192.168.4.1

Adjust settings if needed and control the robot via webpage

Hardware Notes

Motors require a separate power supply

Connect motor GND to ESP32 GND

Ensure motor pins are unique and correct

Summary

This repo contains everything needed to run two robots for Arduino Hackathon football matches:

Defender Robot – blocking and defense code

Player Robot – attacking code

Two connection options: ps5controlcode.ino (Bluetooth) and esp32_phonecontrolviawifi.ino (WiFi)

Full settings panel to adjust all robot parameters

Both robots are ready to assemble, configure, and test.
