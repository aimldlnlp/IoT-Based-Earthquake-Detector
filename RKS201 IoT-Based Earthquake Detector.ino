#include <Wire.h>
#include <MPU6050.h>
#include <U8g2lib.h>

MPU6050 mpu;
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

const int buzzerPin = 18; // Pin untuk buzzer
const int shakeThreshold = 20000; // Ambang batas untuk mendeteksi goyangan

void setup() {
  Wire.begin();
  Serial.begin(115200);
  
  // Initialize the MPU6050
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }
  
  // Initialize the display
  u8g2.begin();

  // Initialize the buzzer pin
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Get raw gyroscope data
  int16_t gx, gy, gz;
  mpu.getRotation(&gx, &gy, &gz);

  // Check if there is a significant shake
  if (abs(gx) > shakeThreshold || abs(gy) > shakeThreshold || abs(gz) > shakeThreshold) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(0, 30);
    u8g2.print("BAHAYA! GEMPA!");
    u8g2.sendBuffer();

    // Loop Buzzer Siren
    unsigned long startTime = millis();
    while (millis() - startTime < 10000) {
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    }

  } else {
    // Clear the display buffer
    u8g2.clearBuffer();

    // Display gyroscope data
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(0, 30);
    u8g2.print("Gyro X: "); u8g2.print(gx);
    u8g2.setCursor(0, 40);
    u8g2.print("Gyro Y: "); u8g2.print(gy);
    u8g2.setCursor(0, 50);
    u8g2.print("Gyro Z: "); u8g2.print(gz);

    // Send buffer to the display
    u8g2.sendBuffer();
  }

  // Add a delay to control the refresh rate
  delay(100);
}