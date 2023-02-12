void ceksd() {
  spiSD.begin(15, 4, 13); //CLK,MISO,MOSI,SS

  if (!SD.begin(SD_CS, spiSD))
  {
    Serial.println("SD Card Error");
    digitalWrite(led, HIGH);
    while (1);
  }
  //  if (!SD.begin(5)) {
  //    Serial.println("ERROR - SD card initialization failed!"); // membaca apabila gagal membaca atau scan sd card
  //    return;    // init failed
  //  }
  //
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");// Tidak ada kartu SD yang terpasang
    while (1) {
      //led error
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      delay(500);
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      delay(500);
    }
  }
}
void cekfilee() {
  Serial.print(" cek file = ");
  boolean ada = 1;
  while (ada == 1) {
    //nomor = nomor + 1;
    sprintf (namaFile, "/suhu kolam buatan%03d.txt", no);
    ada = SD.exists (namaFile);
    if (ada == 1) no ++;
    if (ada == 0) {
      //Membuat File
      Serial.println(namaFile);
      Serial.println(F(" tidak ada"));
      File dataFile = SD.open(namaFile, FILE_WRITE);
      dataFile.println ("Nomor ,DATE,TIME,SUHU AIR 1,SUHU AIR 2,SUHU LUAR ,SUHU AT AIR,TIME1");
      dataFile.close();
    }
  }
}
void simpan(){
  
  sprintf (namaFile, "/suhu kolam buatan%03d.txt", no);
  filename = String(namaFile);
  Serial.println(filename);
  File dataFile = SD.open(filename, FILE_APPEND);
  if (dataFile) {
    //ambilWaktu();
    dataFile.print(counter);
    dataFile.print(",");
    dataFile.print(formatDate + String (",") + String (formatTime));
    dataFile.print(",");
    dataFile.print(suhu1);//suhu air
    dataFile.print(",");
    dataFile.print(suhu3);//suhu ruangan
    //dataFile.println();
    dataFile.close();

    Serial.print(counter);
    Serial.print(",");
    Serial.print(formatDate + String (",") + String (formatTime));
    Serial.print(",");
    Serial.print(suhu1);//suhu air 
    Serial.print(",");
    Serial.print(suhu3);//suhu ruangan
    Serial.println();
    Serial.println("tersimpan");
  }
  else {
    Serial.println("tidak tersimpan");
  }
}
