#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_X 0
#define SERVO_Y 1
#define SERVO_Z 2

#define SERVOMIN 150  // 0도 펄스
#define SERVOMAX 600   // 180도 펄스

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(500);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    pwm.setPWM(SERVO_X, 0, angleToPulse(angle));
    pwm.setPWM(SERVO_Y, 0, angleToPulse(180 - angle));
    pwm.setPWM(SERVO_Z, 0, angleToPulse(angle / 2));

    Serial.print("B,");
    Serial.print(angle); Serial.print(",");
    Serial.print(180 - angle); Serial.print(",");
    Serial.print(angle / 2); Serial.print(",");
    Serial.println(millis());

    delay(15);
  }

  while (1);  // 1회 측정 후 종료
}