#include "BluetoothSerial.h"  // Include Bluetooth Serial library
#include <ESP32Servo.h>        // Include ESP32 Servo library

// Initialize Bluetooth Serial
BluetoothSerial SerialBT;

// Motor Pins
#define MOTOR_FL1 27 // Front-left motor IN1
#define MOTOR_FL2 19 // Front-left motor IN2
#define MOTOR_FR1 23 // Front-right motor IN1
#define MOTOR_FR2 15 // Front-right motor IN2
#define MOTOR_BL1 12 // Back-left motor IN1
#define MOTOR_BL2 18 // Back-left motor IN2
#define MOTOR_BR1 13 // Back-right motor IN1
#define MOTOR_BR2 2  // Back-right motor IN2

// Servo Pin
#define SERVO_PIN 14

Servo myServo;       // Create a servo object
int servoPosition = 0; // Variable to store servo position

// Define PWM channels
const int servoChannel = 0;  // Channel for servo
const int pwmChannel = 1;    // Channel for analog-like signal

char command;  // Variable to store incoming Bluetooth command

void setup() {
  // Set motor pins as outputs
  pinMode(MOTOR_FL1, OUTPUT);
  pinMode(MOTOR_FL2, OUTPUT);
  pinMode(MOTOR_FR1, OUTPUT);
  pinMode(MOTOR_FR2, OUTPUT);
  pinMode(MOTOR_BL1, OUTPUT);
  pinMode(MOTOR_BL2, OUTPUT);
  pinMode(MOTOR_BR1, OUTPUT);
  pinMode(MOTOR_BR2, OUTPUT);

  // Attach the servo to the defined pin
  myServo.attach(SERVO_PIN);
  myServo.write(servoPosition); // Initialize servo position

  // Start Bluetooth Serial with a name for the ESP32
  SerialBT.begin("TEAM_BLUE");
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  // Check if there's a Bluetooth command available
  if (SerialBT.available()) {
    command = SerialBT.read();  // Read the incoming command

    // Perform action based on command
    switch (command) {
      case 'B':  // Forward
        moveForward();
        break;
      case 'F':  // Backward
        moveBackward();
        break;
      case 'L':  // Left
        moveLeft();
        break;
      case 'R':  // Right
        moveRight();
        break;
      case 'C':  // Rotate Clockwise
        rotateClockwise();
        break;
      case 'G':  // Rotate Anti-clockwise
        rotateAnticlockwise();
        break;
      case 'S':  // Stop
        stopMotors();
        break;
      case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        setServoPosition((command - '0') * 10); // Set servo position from 10 to 90 degrees
        break;
    }
  }
}

// Movement Functions

void moveForward() {
  analogWrite(MOTOR_FL1, 230);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, 230);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, 230);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, 230);
}

void moveBackward() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, 230);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, 230);
  analogWrite(MOTOR_BL1, 230);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, 230);
  analogWrite(MOTOR_BR2, 0);
}

void moveLeft() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, 230);
  analogWrite(MOTOR_FR1, 230);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, 230);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, 230);
}

void moveRight() {
  analogWrite(MOTOR_FL1, 230);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, 230);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, 230);
  analogWrite(MOTOR_BR1, 230);
  analogWrite(MOTOR_BR2, 0);
}

void rotateClockwise() {
  analogWrite(MOTOR_FL1, 230);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, 230);
  analogWrite(MOTOR_BL1, 230);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, 230);
}

void rotateAnticlockwise() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, 230);
  analogWrite(MOTOR_FR1, 230);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, 230);
  analogWrite(MOTOR_BR1, 230);
  analogWrite(MOTOR_BR2, 0);
}

void stopMotors() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, 0);
}

void setServoPosition(int position) {
  servoPosition = position;
  myServo.detach();           // Detach the servo to reset
  delay(10);                  // Small delay to ensure detachment
  myServo.attach(SERVO_PIN);  // Reattach the servo
  myServo.write(servoPosition);
}