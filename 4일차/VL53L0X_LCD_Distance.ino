#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <LiquidCrystal_I2C.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
LiquidCrystal_I2C lcd(0x27, 16, 2);

VL53L0X_RangingMeasurementData_t measure; // 라이브러리 안에 헤더파일안에 구조체 선언되어있음.

void setup() {
  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();

  if (!lox.begin()) {
    Serial.println("센서 초기화 실패!");
    lcd.setCursor(0, 0);
    lcd.print("센서 오류");
    while (1);
  }

  lcd.setCursor(0, 0);
  lcd.print("VL53L0X Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  lox.rangingTest(&measure, false);  // 측정 실행

  if (measure.RangeStatus == 0) {
    int dist = measure.RangeMilliMeter;

    Serial.print("거리: ");
    Serial.print(dist);
    Serial.println(" mm");

    lcd.setCursor(0, 0);
    lcd.print("Distance:");
    lcd.setCursor(0, 1);
    lcd.print(dist);
    lcd.print(" mm    ");
  } else {
    Serial.println("측정 실패");

    lcd.setCursor(0, 0);
    lcd.print("측정 실패       ");
    lcd.setCursor(0, 1);
    lcd.print("               ");
  }

  delay(2000);
}