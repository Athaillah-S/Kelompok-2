void loop() {

  state = analogRead(sensorPin);
//  Serial.println(state);
  if(state < 500) {
      
      if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
     
        HTTPClient http;
     
        int nilai = random(29,37);
        String data = (String) nilai;
//        String link = "-" + state;
        String link = "-" + account_sid + "&auth_token="+ auth_token +"&to_wa=" + to + "&from_wa="+ from +"&body_message=" + body;
        
        http.begin(link);
        int httpCode = http.GET();
        Serial.println(httpCode);
        
        if (httpCode > 0) { //Check for the returning code
            
            String payload = http.getString();
            Serial.println(link);
            Serial.println(httpCode);
            Serial.println(payload);
        }
        else {
            Serial.println("Error on HTTP request");
        }
        http.end();
      }
      digitalWrite(speakerPin, HIGH);
      delay(3000);
      digitalWrite(speakerPin, LOW);
      delay(1000);
  }
  delay(200);
 
}
