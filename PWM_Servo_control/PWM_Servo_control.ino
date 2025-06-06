#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_X_CH 0
#define SERVO_Y_CH 1

#define SERVOMIN 150
#define SERVOMAX 600

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // 50Hz
  delay(10);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    pwm.setPWM(SERVO_X_CH, 0, angleToPulse(angle));
    pwm.setPWM(SERVO_Y_CH, 0, angleToPulse(180 - angle));
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  X pos: ");
    Serial.print(angleToPulse(angle));
    Serial.print("  Y pos: ");
    Serial.println(angleToPulse(180 - angle));
    delay(10);
  }

  while (true); // 루프 종료
}

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
