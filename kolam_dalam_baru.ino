//config
#include "config.h" //semua config 

//antares
#include <AntaresESP32HTTP.h>
#define projectName "Aquaculture"
#define deviceName "Wifi_DO_SUHU"
#define ACCESSKEY "89992da001a0228b:e5bd085df2cd162d"
AntaresESP32HTTP antares(ACCESSKEY);

// SD CARD
#include "FS.h"
#include "SD.h"
#include <SPI.h>
#include <SD.h>
SPIClass spiSD(HSPI);
File myFile;
String filename;

// waktu
#include <WiFi.h>
#include <NTPClient.h> //Library Network Time Protocol
#include <WiFiUdp.h>//Library WiFiUdp
WiFiUDP ntpUDP; //Deklarasi ntpUDP agar dapat mengirim dan menerima pesan UDP
NTPClient timeClient(ntpUDP);//Menghubungkan ke server NTP
WiFiClient  client;

//librari untuk ds18b20
#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire3(ONE_WIRE_BUS2);
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire3);

//tft SPI
#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
TFT_eSPI tft = TFT_eSPI();  // Invoke library

void setup() {
  //Wire.begin();
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  //cek tft
  cektft();
  //cek sd
  ceksd();
  //cek  file di sd card 
  cekfilee();
  //sensor
  sensors1.begin(); //  sensor ds1
  sensors3.begin(); //  sensor ds2
  //wifi setup
  wifisetup();
  //waktu setup
  waktusetup();
  //tampilan awal
  tampilAwal();
  delay(3000);
}
void loop() {
  counter++;
  //pengambilan data sensor
  sensorDF();
  sensorDS1();
  //pengambilan data waktu
  updatewaktu();
  //menampilkan to TFT
  tampilTFT();
  //penyimpan data to SD
  simpan();
  //pengiriman data
  kirimdata();
  //pengambilan waktu baru
  updatewaktuserver();
  Led();
  delay(intrvl);
}
