# IoT-Based Earthquake Detector

## Introduction

Earthquakes are generally caused by the movement of tectonic plates, resulting in vibrations that can cause significant damage to buildings and infrastructure. Effective disaster mitigation, such as an earthquake early warning system, is crucial for earthquake-prone countries like Indonesia to reduce risks and impacts. This project proposes a prototype titled **"IoT-Based Earthquake Detector"** designed to detect vibrations with high accuracy.

## Overview

The earthquake detector utilizes the **MPU6050 gyro sensor** to detect tilt on the x, y, and z axes, connected to an **ESP32 microcontroller**. It features an **OLED display** for real-time data monitoring and utilizes **Blynk firmware** for remote monitoring and instant notifications during significant tilt changes. The data is stored and processed efficiently using Firebase as an online database, ensuring accurate and up-to-date information for users.

## System Architecture

### Diagram Overview

The system architecture includes the following components:

- **ESP32**: The main controller receiving data from the MPU6050 sensor.
- **MPU6050 Sensor**: Detects changes in x, y, and z axes.
- **OLED Display**: Displays real-time values from the sensor.
- **Buzzer**: Alerts when values exceed a predefined threshold.

### Pin Configuration

| **Pin ESP32** | **Function**                                    |
|---------------|-------------------------------------------------|
| GPIO21 (SDA)  | I2C Data for communication with MPU6050 and OLED display |
| GPIO22 (SCL)  | I2C Clock for communication with MPU6050 and OLED display |
| GPIO18        | Output for controlling the buzzer               |

## Component Explanation

1. **LCD OLED SSD1306**: Displays real-time data measured by the MPU6050, including acceleration and rotation. It can also visualize intensity and duration of vibrations.
  
2. **ESP32**: A microcontroller with WiFi and Bluetooth capabilities, allowing real-time data transmission and quick alerts.

3. **Gyro MPU6050**: A combined accelerometer and gyroscope sensor that detects movements and vibrations across three axes.

4. **Breadboard**: Used for assembling the circuit temporarily without soldering components.

5. **Power Supply Module**: Ensures a stable power supply for all components, protecting them from voltage spikes.

6. **Jumper Wires**: Used to connect components on the breadboard or PCB.

7. **Buzzer**: Emits sound when the earthquake detector identifies vibrations that exceed a certain threshold.

