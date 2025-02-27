# Manual-and-Automatic-Robot-Car
# Arduino Robot Car (Manual & Automatic Mode)

## Project Overview
This project is an Arduino-based robot car that operates in both manual and automatic modes. It uses:
- **Arduino Uno** as the main controller
- **Ultrasonic Sensor** for obstacle detection in automatic mode
- **Servo Motor** to rotate ultrasonic sensor
- **Bluetooth Module (HC-05/HC-06)** to connect with a smartphone for manual control
- **Touch Sensor** to switch between manual and automatic modes

The Arduino Uno is programmed in **C++**, and the source code is available in this repository.

## Features
- **Manual Mode**: Controlled via a smartphone app through Bluetooth connection.
- **Automatic Mode**: Uses an ultrasonic sensor to detect and avoid obstacles.
- **Mode Switching**: A touch sensor allows switching between manual and automatic modes.
- **Arduino-Controlled**: All functionalities are implemented using an Arduino Uno.

## Components Used
- **Arduino Uno**
- **Ultrasonic Sensor (HC-SR04)**
- **Servo Motor**
- **Bluetooth Module (HC-05/HC-06)**
- **Touch Sensor**
- **Motor Driver (L298N)**
- **DC Motors & Wheels**
- **Battery Pack**

## How It Works
1. **Power On**: The robot car initializes with default settings.
2. **Mode Selection**:
   - If the touch sensor is pressed, the car switches between **manual** and **automatic** mode.
3. **Manual Mode**:
   - The car is controlled via a smartphone app using Bluetooth commands.
4. **Automatic Mode**:
   - The ultrasonic sensor detects obstacles and the robot car navigates autonomously.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
