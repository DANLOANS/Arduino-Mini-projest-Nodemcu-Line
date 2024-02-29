int moistureSensorPin = A0;  // กำหนดชื่อใหม่สำหรับตัวแปรที่ใช้ในการอ่านค่าความชื้น
int moistureValue = 0;       // กำหนดชื่อใหม่สำหรับตัวแปรที่ใช้เก็บค่าความชื้น
int notificationSent = 0;    // กำหนดชื่อใหม่สำหรับตัวแปรที่ใช้เก็บสถานะการส่งการแจ้งเตือน

#include <TridentTD_LineNotify.h>

#define WIFI_SSID       "arduino_wifi"      // เปลี่ยนชื่อ WiFi ตามที่ต้องการ
#define WIFI_PASSWORD   "wifi_password"     // เปลี่ยนรหัส WiFi ตามที่ต้องการ
#define LINE_TOKEN      "8DYAF27UyN3P53KaGz3h6lDILU4aBMAgYZ8wIAkMPLa"   // ใส่ Token ของ LINE ที่ได้รับ

String notificationMessage = "ค่าความชื้นสูงเกินไป"; // เปลี่ยนข้อความการแจ้งเตือนตามที่ต้องการ

void setup() {
  Serial.begin(9600);
  Serial.println(LINE.getVersion());

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.printf("Connecting to WiFi network: %s\n",  WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP Address: ");
  Serial.println(WiFi.localIP());

  // กำหนด Token ของ LINE
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  moistureValue = analogRead(moistureSensorPin);  // อ่านค่าความชื้นจากเซ็นเซอร์
  Serial.print("Moisture value: ");              // พิมพ์ค่าความชื้นไปยังคอนโซล
  Serial.println(moistureValue);                 // พิมพ์ค่าความชื้นไปยังคอนโซล

  // เช็คค่าความชื้นและสถานะการส่งการแจ้งเตือน
  if (moistureValue < 500 && notificationSent == 0) {
    LINE.notify(notificationMessage);  // ส่งการแจ้งเตือนไปยัง LINE
    delay(1000);
    notificationSent = 1;  // อัพเดทสถานะการส่งการแจ้งเตือน
  } 
  else if (moistureValue >= 500) {
    notificationSent = 0;  // รีเซ็ตสถานะการส่งการแจ้งเตือน
  }

  delay(1000);
}
