#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD 객체 생성 (주소 0x27, 16열 2행)
LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  LCD.init();         // LCD 초기화
  LCD.backlight();    // 백라이트 켜기
}

void loop() {
  LCD.setCursor(2, 0);
  LCD.print("HELLO WORLD!");
  LCD.setCursor(0, 1); 
  LCD.print("WELCOME Arduino!");
  delay(3000);

  for (int i = 0; i < 7; i++) {
    LCD.scrollDisplayLeft();
    delay(300);
  }
  delay(2000);

  for (int i = 0; i < 23; i++) {
    LCD.scrollDisplayRight();
    delay(300);
  }
  delay(2000);

  for (int i = 0; i < 16; i++) {
    LCD.scrollDisplayLeft();
    delay(300);
  }
  delay(2000);

  LCD.clear();
  delay(1000);
}