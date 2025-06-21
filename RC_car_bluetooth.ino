#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(2, 3); // TX and RX pins for HC-05 Bluetooth module

// L293D Motor Driver Pins
const int enable_pin_a = 9;
const int enable_pin_b = 10;

// Left Motor
const int motorPin1 = 5;  // Pin 4 of L293D
const int motorPin2 = 6;  // Pin 7 of L293D
// Right Motor
const int motorPin3 = 7;  // Pin 8 of L293D
const int motorPin4 = 8;  // Pin 9 of L293D

void setup() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(enable_pin_a, OUTPUT);
    pinMode(enable_pin_b, OUTPUT);

    bluetoothSerial.begin(9600);
    Serial.begin(9600);
    delay(10);
}

void loop() {
    if (bluetoothSerial.available() > 0) {
        char command = bluetoothSerial.read();
        Serial.println(command);

        // Execute motor control based on command
        if (command == 'F') {
            forward();
            Serial.println("Forward");
        } else if (command == 'B') {
            backward();
            Serial.println("Backward");
        } else if (command == 'L') {
            turnLeft();
            Serial.println("Left");
        } else if (command == 'R') {
            turnRight();
            Serial.println("Right");
        } else if (command == 'S') {
            stop();
            Serial.println("Stop");
        }
    }
}

void forward() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    analogWrite(enable_pin_a, 150); // Adjust speed if needed
    analogWrite(enable_pin_b, 150);
}

void backward() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    analogWrite(enable_pin_a, 150);
    analogWrite(enable_pin_b, 150);
}

void turnLeft() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    analogWrite(enable_pin_a, 120);
    analogWrite(enable_pin_b, 120);
}

void turnRight() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    analogWrite(enable_pin_a, 120);
    analogWrite(enable_pin_b, 120);
}

void stop() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}
