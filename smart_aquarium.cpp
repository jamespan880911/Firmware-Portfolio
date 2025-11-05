#include <OneWire.h>
#include <DallasTemperature.h>

//定義接腳
#define ONE_WIRE_BUS 2       
#define RELAY_COOLER 7       
#define RELAY_FAN 8          


const float TEMP_HIGH = 20.0;    // 超過此值啟動製冷與風扇
const float TEMP_LOW  = 16.0;    // 降到此值關閉製冷，風扇延遲關閉
const unsigned long FAN_DELAY = 600000; // 風扇delay (ms)


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

bool coolerOn = false;
unsigned long fanOffTime = 0;

void setup() {
  Serial.begin(9600);
  sensors.begin();

  pinMode(RELAY_COOLER, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);

  digitalWrite(RELAY_COOLER, LOW);
  digitalWrite(RELAY_FAN, LOW);

  Serial.println("Smart Aquarium Temperature Control System Started.");
}

void loop() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Current Water Temp: ");
  Serial.print(temp);
  Serial.println(" °C");

  // 開啟製冷晶片與風扇
  if (temp > TEMP_HIGH) {
    digitalWrite(RELAY_COOLER, HIGH);
    digitalWrite(RELAY_FAN, HIGH);
    coolerOn = true;
  }
  // 關閉製冷晶片，延遲風扇關閉
  else if (temp < TEMP_LOW && coolerOn) {
    digitalWrite(RELAY_COOLER, LOW);
    fanOffTime = millis() + FAN_DELAY;
    coolerOn = false;
  }

  // 檢查風扇開關
  if (!coolerOn && millis() > fanOffTime) {
    digitalWrite(RELAY_FAN, LOW);
  }

  delay(2000); // 每2秒更新一次
}