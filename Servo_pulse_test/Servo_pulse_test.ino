#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVO_CH 0

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50); // 서보모터용 주파수 (50Hz)

  delay(1000);
  Serial.println("서보 펄스 범위 테스트 시작");

  for (int pulse = 100; pulse <= 600; pulse += 5) {
    pwm.setPWM(SERVO_CH, 0, pulse);
    Serial.print("Pulse: ");
    Serial.println(pulse);
    delay(1000);
  }

  Serial.println("테스트 완료");
}

void loop() {
}
