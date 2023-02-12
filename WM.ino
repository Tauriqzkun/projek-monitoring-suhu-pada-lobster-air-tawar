void wifisetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void kirimdata() {
  suhu01 = suhu1;
  suhu02 = suhu2;
  Rssi = WiFi.RSSI();
  RSSII = Rssi;
  conter = counter;
  antares.add("Kolam", String("Kolam Dalam"));
 // antares.add("jumlah",  conter);
  antares.add("Suhu B Air 1", suhu01);
  antares.add("Suhu B Luar", suhu02);
  antares.add("formatTime", formatTime);
  antares.add("formatDate", formatDate);
  antares.add("RSSI", Rssi + String (" dBm"));
  antares.send(projectName, deviceName);
  tft.setCursor(150, 210);
  tft.print("TERKIRIM ");
}

void waktusetup() {
  timeClient.begin(); //Memulai Network Time Protocol
  timeClient.setTimeOffset(25200);  // server id indonesia
}
void updatewaktu() {
  timeClient.update();//Update Network Time Protocol //
  //  setting date
  unsigned long epochTime = timeClient.getEpochTime();// mengambil waktu masa
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  tanggal = ptm->tm_mday; // membaca tanggal
  bulan = ptm->tm_mon + 1; //membaca bulan
  tahun = ptm->tm_year + 1900; // membaca tahun
  // date:
  formatDate = String(tanggal) + "/" + String(bulan ) + "/" + String(tahun);
  // time
  formatTime = timeClient.getFormattedTime();// dapatkan waktu dengan format jam:menit:detik
}
void updatewaktuserver() {
  // time
  formatTime1 = timeClient.getFormattedTime();// dapatkan waktu dengan format jam:menit:detik
  //simpan waktu setelah data berhasil diterima oleh server
  filename = String(namaFile);
  Serial.println(filename);
  File dataFile = SD.open(filename, FILE_APPEND);
  dataFile.print(",");
  dataFile.println(formatTime1);
  // dataFile.println();
  dataFile.close();
  Serial.println(formatTime1);
}
