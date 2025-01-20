#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// konfigurasi WiFi
const char* ssid = "masukan nama wifi"; //Ganti dengan nama wifi kalian
const char* password = "masukan password wifi"; // paswword wifi kalian

// bot Telegram
#define BOT_TOKEN "masukkan token bot " //token bot telegram "wadah pesan"
#define CHAT_ID "masukan id telegram" //id telegram agar dapat mengirim pesan ke pengguna

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client); 

// **Konfigurasi pin**
const int sensorPin = D5; //pin sensor infrared
const int buzzerPin = D6; //pin buzzer atau alarm
int lastSensorState = HIGH; //status awal sensor (pintu tertutup/tidak ada objek)
void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  // Koneksi WiFi
  Serial.print("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Terhubung!");

  // Koneksi aman untuk Telegram
  client.setInsecure(); 

  // Notifikasi awal
  bot.sendMessage(CHAT_ID, "Sistem Sensor Pintu Aktif", "");
}
