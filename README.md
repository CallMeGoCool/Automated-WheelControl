# Automated-WheelControl
An automated module that can control any wheeled device using Arduino, a bluetooth module, a joystick and a DC motor.

Take a look at the prototype
![Side View](assets/side%20view.jpg)
![Front Side](assets/front%20side.jpg)
Here’s a close-up view of the connection side:
![Connection Side](assets/connection%20side.jpg)



MobiCool: Automated Wheel Control Module
MobiCool is an innovative, modular control system designed to automate the movement of any wheeled device. The system provides dual control modes using:
    1. Voice Commands – Hands-free operation via Bluetooth.
    2. Joystick Control – Manual analog input for precise navigation.

Project Overview
Commercial motorized wheelchairs in India typically cost around ₹50,000, while voice-controlled models can reach ₹1.5 lakh, making them inaccessible to many. MobiCool offers a low-cost alternative by enabling automation for wheeled devices at an estimated price of ₹5,000 – ₹6,000.

Key Features
1. Dual Control Modes: Switch between voice commands and joystick seamlessly.
2. Low-Cost Prototype: Built using affordable and easily accessible components.
3. Real-Time Response: Smooth, lag-free control with accurate feedback.
4. Modular Design: Can be attached to any wheeled platform, enhancing its versatility.

How It Works
    Control Modes
        1. Voice Control (via Bluetooth):
                Commands: forward, backward, left, right, halt
                Communication using a Bluetooth module (HC-05/HC-06)
        2. Joystick Control (Analog Input):
                Forward and backward movement by tilting the joystick up and down.
                Left and right movement by tilting the joystick sideways.
                Joystick press triggers a halt.
    Motor Control Logic
        Motor Driver Configuration: Dual L298N motor drivers for independent motor control.
        Command-based movement using digitalWrite for motor pins.
        Automatic stop when joystick returns to neutral.

Components Used

_________________________________________________________________________________________________________
|   Component	                      |          Quantity	     |       Purpose                        |
---------------------------------------------------------------------------------------------------------
|   Arduino UNO	                      |          1	             |       Main microcontroller           |
|   L298N Motor Driver Module	      |          2	             |       Dual motor control             |
|   HC-05/HC-06 Bluetooth Module	  |          1	             |       Voice command reception        |
|   Joystick Module	                  |          1	             |       Manual control                 |
|   06V DC Motors	                  |          4       	     |       Motorizing the wheels          |
|   12V Battery	                      |          2 or 3          |       Power supply                   |
|   LEDs	                          |          1	             |       Visual status indicator        |
|   Resistors and Wires	              |          As required	 |       Circuit connections            |
_________________________________________________________________________________________________________

Wheelchair Sizes:
1. Front Wheel:    15cm diameter
2. Rear Wheel:     30cm diameter
3. Backrest:       50cm length x 30cm width
4. Seat:           30cm length x 30cm width
5. Footrest:       30cm length x 30cm width