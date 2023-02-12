//ds18b20
#define ONE_WIRE_BUS1 17 //suhu buatan air
#define ONE_WIRE_BUS2 33 //suhu buatan luar
#define ONE_WIRE_BUS3 16 //suhu buatan air
//#define ONE_WIRE_BUS4 16
//#define ONE_WIRE_BUS5 27
//#define ONE_WIRE_BUS6 16

float suhu1, suhu2, suhu3, suhu4, suhu5, suhu6, suhu006, suhuAT= 1;
String suhu01, suhu02, suhu03, suhu04, suhu05, suhu06, suhu0AT, RSSII, conter;

float kalibirasi1, kalibirasi2, kalibirasi3; //AT
float kalibirasi4, kalibirasi5, kalibirasi6; // suhu
long Rssi;
String pH, suhu, ec;
byte led = 26;

//sdcard
#define SD_CS 12
char namaFile [13];
String dataMessage;
RTC_DATA_ATTR int no = 0;
RTC_DATA_ATTR int counter = 0;

//waktu
//char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"}; //Array yang berisi hari pada satu minggu
int tanggal, bulan, tahun;
String formatTime, formatDate,formatTime1, formatDate1; //variabe untuk waktu dengan type string
const long utcOffsetInSeconds = 3600 * 7; // id waktu negara indonesia / waktu server 25200 (revisi)

//wifi setup
const char *ssid     = "Tselhome";
const char *password = "12345";
//const char *ssid     = "BRIN_Net";
//const char *password = "";
//const char *ssid     = "kun";
//const char *password = "rican0987";

//delay
int intrvl = 10 * 60 * 1000;
