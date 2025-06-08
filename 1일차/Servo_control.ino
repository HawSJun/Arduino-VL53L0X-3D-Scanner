#include <Servo.h>

Servo servoX;
Servo servoY;

const int servoXPin = 9;   // X축 서보 핀
const int servoYPin = 10;  // Y축 서보 핀

void setup() {
  Serial.begin(9600);

  // 서보 핀 연결
  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
}

void loop() {
  for (int angle = 0; angle <= 180;  angle += 10) {
    servoX.write(angle);          // X축: 0 → 180도
    servoY.write(180 - angle);    // Y축: 180 → 0도 (반대 방향)

    // 로그 출력
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  X pos: ");
    Serial.print(angle);
    Serial.print("  Y pos: ");
    Serial.println(180 - angle);

    delay(500);
  }

  while (true);  // 루프 종료
}