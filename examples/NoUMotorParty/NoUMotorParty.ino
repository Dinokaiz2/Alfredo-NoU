#include <Alfredo_NoU.h>

NoU_Motor frontLeftMotor(1);
NoU_Motor frontRightMotor(2);
NoU_Motor rearLeftMotor(3);
NoU_Motor rearRightMotor(4);
NoU_Servo servo1(16);
NoU_Servo servo2(17);
NoU_Servo servo3(18);
NoU_Servo servo4(19);

void setup() {
    Serial.begin(9600);
    RSL::initialize();
    RSL::setState(RSL_ENABLED);
}

void loop() {
    for (float i = -1023; i < 1023; i += 1) {
        frontLeftMotor.set(i / 1023.0);
        frontRightMotor.set(i / 1023.0);
        rearLeftMotor.set(i / 1023.0);
        rearRightMotor.set(i / 1023.0);
        servo1.write(map(i, -1023, 1023, 0, 180));
        servo2.write(map(i, -1023, 1023, 0, 180));
        servo3.write(map(i, -1023, 1023, 0, 180));
        servo4.write(map(i, -1023, 1023, 0, 180));
        RSL::update();
        delay(1);
    }
    for (float i = 1023; i > -1023; i -= 1) {
        frontLeftMotor.set(i / 1023.0);
        frontRightMotor.set(i / 1023.0);
        rearLeftMotor.set(i / 1023.0);
        rearRightMotor.set(i / 1023.0);
        servo1.write(map(i, -1023, 1023, 0, 180));
        servo2.write(map(i, -1023, 1023, 0, 180));
        servo3.write(map(i, -1023, 1023, 0, 180));
        servo4.write(map(i, -1023, 1023, 0, 180));
        RSL::update();
        delay(1);
    }
}