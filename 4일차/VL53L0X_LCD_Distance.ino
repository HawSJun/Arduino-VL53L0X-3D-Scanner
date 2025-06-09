#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <LiquidCrystal_I2C.h>  // LCD 라이브러리

// 객체 생성
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 주소 0x27, 16x2

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    delay(1);  // USB 연결 대기 (native USB 보드용)
  }

  // LCD 초기화
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("VL53L0X Start...");

  // 센서 초기화
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    lcd.clear();
    lcd.print("Sensor Fail");
    while (1);  // 초기화 실패 시 멈춤
  }

  Serial.println(F("VL53L0X\n\n"));
  lcd.clear();
  lcd.print("Sensor Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {
    // 정상 측정
    Serial.print("Distance (mm): ");
    Serial.println(measure.RangeMilliMeter);

    lcd.setCursor(0, 0);
    lcd.print("Distance:       ");  // 이전 글자 덮기 위해 공백 추가
    lcd.setCursor(0, 1);
    lcd.print(measure.RangeMilliMeter);
    lcd.print(" mm     ");
  } else {
    Serial.println(" out of range ");

    lcd.setCursor(0, 0);
    lcd.print("Distance:       ");
    lcd.setCursor(0, 1);
    lcd.print("Out of range   ");
  }

  delay(200);
}