void cektft() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}
void tampilAwal() {
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(70, 20);
  tft.println("SMART MONITORING");
  tft.setCursor(90, 40);
  tft.println("BRIN BANDUNG");
  tft.setCursor(200, 200);
  tft.println("BY TAURIQ");

  tft.setTextSize(1.5);
  tft.setCursor(30, 140);
  tft.print(WiFi.localIP());
  //  tft.print + String("/update"));
  tft.setTextSize(1.5);
  tft.setCursor(10, 170);
  tft.print("Nama File" + String (namaFile));
}
void tampilTFT() {
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(50, 10);
  tft.print("SMART MONITORING ");
  tft.setCursor(70, 30);
  tft.print("BRIN BANDUNG");
  tft.setCursor(20, 60);
  tft.print("SUHU B Air 1  : " + String (suhu1));
  tft.setCursor(20, 80);
  tft.print("SUHU B Luar   : " + String (suhu2));
  
//  tft.setCursor(20, 160);
//  tft.print("    JUMLAH    : " + String (counter));
  tft.setCursor(110, 180);
  tft.print(formatTime);
  long rssi = WiFi.RSSI();
  tft.setCursor(50, 200);
  tft.print(String (rssi) + String(" dBm"));
  tft.setTextSize(1);
  tft.setCursor(50, 230);
  tft.print(WiFi.localIP());

}
void sensorDF() {
  sensors1.requestTemperatures(); // Send the command to get temperatures
 kalibirasi4 = sensors1.getTempCByIndex(0);
  suhu1 = 0.9577 * kalibirasi4 + 1.3216;// DF
  if (suhu1 != DEVICE_DISCONNECTED_C)
  {

    Serial.print("suhu 1 : ");
    Serial.print(suhu1);
    Serial.println(" °C ");

  }
  else
  {
    Serial.println("Error: suhu1 Could not read temperature data");
  }
}

void sensorDS2() {
  sensors3.requestTemperatures(); // Send the command to get temperatures

  kalibirasi6 = sensors3.getTempCByIndex(0);
  suhu3 = 0.937 * kalibirasi6 + 2.13;

  if (suhu3 != DEVICE_DISCONNECTED_C)
  {

    Serial.print("suhu 3 : ");
    Serial.print(suhu3);
    Serial.println(" °C ");

  }
  else
  {
    Serial.println("Error: suhu3 Could not read temperature data");
  }

}
void Led() {

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
}
