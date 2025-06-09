#include <Wire.h>
#include <VL53L0X.h>
#include <LiquidCrystal_I2C.h>

// 객체 생성
VL53L0X sensor;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD 주소 0x27, 16x2

void setup() {
  Serial.begin(115200);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Starting sensor");
  delay(2000);


  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("VL53L0X init failed!");
    lcd.clear();
    lcd.print("Sensor Error");
    while (1);  // 센서 초기화 실패 시 멈춤
  }


  sensor.setSignalRateLimit(0.1);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  sensor.setMeasurementTimingBudget(200000);

  sensor.startContinuous();  // 연속 측정 시작

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int distance = sensor.readRangeContinuousMillimeters();

  if (sensor.timeoutOccurred()) {
    Serial.println("TIMEOUT");
    lcd.print("Timeout Error");
  } 
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");

    lcd.setCursor(3, 0);
    lcd.print("Distance!!");
    lcd.setCursor(5, 1);
    lcd.print(distance);
    lcd.print("mm   ");
  }

  delay(200);  // 측정 간격
}