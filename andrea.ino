void loop() {
  // Membaca status sensor
  int sensorState = digitalRead(sensorPin);

  // Mengecek apakah ada perubahan status pada sensor
  if (sensorState != lastSensorState) {
    lastSensorState = sensorState;
    
    if (sensorState == LOW) { 
      Serial.println("PINTU ADA YANG BUKA!");
      digitalWrite(buzzerPin, HIGH); 
      bot.sendMessage(CHAT_ID, "PINTU ADA YANG BUKA!", "");
    } else { 
      Serial.println("Pintu tertutup.");
      digitalWrite(buzzerPin, LOW); 
      bot.sendMessage(CHAT_ID, "Pintu tertutup.", "");
    }
  }
  delay(500); 
}
