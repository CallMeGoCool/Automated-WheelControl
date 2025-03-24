// ==============================
// Pin Configuration
// ==============================

// Motor A (Back Right)
const int M1A = 2;
const int M1B = 3;

// Motor B (Back Left)
const int M2A = 4;
const int M2B = 5;

// Motor C (Front Left)
const int M3A = 6;
const int M3B = 7;

// Motor D (Front Right)
const int M4A = 8;
const int M4B = 9;

// Joystick Pins
const int VRx = A0;  // X-axis for right/left
const int VRy = A1;  // Y-axis for forward/backward
const int SW = 10;   // Joystick button (press for halt)

// LED Pin
const int LED_PIN = 13;

// ==============================
// Joystick Calibration
// ==============================

const int deadZone = 50;    // Ignore slight joystick movements
const int centerValue = 338; // Updated joystick center value

// Flag to track mode
bool voiceModeActive = false;  // False by default - joystick control

void setup() {
  Serial.begin(9600);

  // Set all motor pins as output
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  // Joystick button as input with pullup
  pinMode(SW, INPUT_PULLUP);

  // LED Pin as output, always HIGH by default
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // LED ON by default

  // Stop motors initially
  stopMotors();
  Serial.println("MobiCool System Ready! Voice and Joystick Control Enabled.");
}

void loop() {
  joystickControl();  // Check joystick input
  voiceControl();     // Check for voice commands
}

// ==============================
// Voice Control Logic
// ==============================

void voiceControl() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');  // Read until newline
    command.trim();  // Remove any leading/trailing spaces
    command.toLowerCase();  // Convert to lowercase for consistency

    // Activate voice mode when a valid command is received
    voiceModeActive = true;

    if (command == "forward") {
      forward();
      Serial.println("Moving Forward...");
    } 
    else if (command == "backward") {
      backward();
      Serial.println("Moving Backward...");
    } 
    else if (command == "left") {
      left();
      Serial.println("Turning Left...");
    } 
    else if (command == "right") {
      right();
      Serial.println("Turning Right...");
    } 
    else if (command == "halt") {  // Stop when commanded
      stopMotors();
      Serial.println("Halting...");
    } 
    else {
      Serial.println("Invalid Voice Command!");
    }
  }
}

// ==============================
// Joystick Control Logic
// ==============================

void joystickControl() {
  int xValue = analogRead(VRx);  // Read X-axis
  int yValue = analogRead(VRy);  // Read Y-axis
  bool buttonPressed = (digitalRead(SW) == LOW);  // Check if joystick button is pressed

  // Check joystick only if NOT in voice mode
  if (!voiceModeActive) {
    // Forward (Y > center + dead zone)
    if (yValue > centerValue + deadZone) {
      forward();
      Serial.println("Joystick: Moving Forward...");
    }
    // Backward (Y < center - dead zone)
    else if (yValue < centerValue - deadZone) {
      backward();
      Serial.println("Joystick: Moving Backward...");
    }
    // Right (X > center + dead zone)
    else if (xValue > centerValue + deadZone) {
      right();
      Serial.println("Joystick: Turning Right...");
    }
    // Left (X < center - dead zone)
    else if (xValue < centerValue - deadZone) {
      left();
      Serial.println("Joystick: Turning Left...");
    }
    // Joystick back to neutral -> Stop
    else {
      stopMotors();
    }

    // Switch back to joystick mode when joystick moves
    if (abs(xValue - centerValue) > deadZone || abs(yValue - centerValue) > deadZone) {
      voiceModeActive = false;
    }
  }

  // Halt if joystick button is pressed
  if (buttonPressed) {
    stopMotors();
    Serial.println("Joystick Pressed: Halting...");
  }
}

// ==============================
// Motor Control Functions
// ==============================

// Move Forward
void forward() {
  digitalWrite(M1A, HIGH); digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH); digitalWrite(M2B, LOW);
  digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW);
  digitalWrite(M4A, HIGH); digitalWrite(M4B, LOW);
}

// Move Backward
void backward() {
  digitalWrite(M1A, LOW); digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW); digitalWrite(M2B, HIGH);
  digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH);
  digitalWrite(M4A, LOW); digitalWrite(M4B, HIGH);
}

// Turn Right
void right() {
  digitalWrite(M1A, HIGH); digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH); digitalWrite(M2B, LOW);
  digitalWrite(M3A, LOW);  digitalWrite(M3B, HIGH);
  digitalWrite(M4A, LOW);  digitalWrite(M4B, HIGH);
}

// Turn Left
void left() {
  digitalWrite(M1A, LOW); digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW); digitalWrite(M2B, HIGH);
  digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW);
  digitalWrite(M4A, HIGH); digitalWrite(M4B, LOW);
}

// Stop Motors
void stopMotors() {
  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  Serial.println("Motors Stopped.");
}
