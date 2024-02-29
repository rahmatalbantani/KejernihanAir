#include <Arduino.h>

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL6-1fQJZaN"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "MK2gC_yzN4y20AQMsnHmdUY0j51H0a4w"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] ="UNTIRTAKU";
char pass[] ="untirtajawara";


int i;
bool parsing= false;
String sData,data[10];

BlynkTimer timer;

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
  Blynk.virtualWrite(V4, data[1]);
  Blynk.virtualWrite(V0, data[3]);
  Blynk.virtualWrite(V3, data[2]);
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);


}

void loop() {
  Blynk.run();
  timer.run();

 while(Serial.available()){
   char inChar = Serial.read();
   sData += inChar;
   if(inChar=='$'){
     parsing=true;
   }
   if(parsing==true){
     int q = 0;
     for(int i =0; i<sData.length();i++){
       if(sData[i]=='#'){
         q++;
         data[q]="";
       }else{
         data[q]+=sData[i];
       }
     }
    Serial.println("Data Masuk" + sData);
    Serial.println("pH :" + data[1]);
    Serial.println("Turbidity :" + data[2]);
    Serial.println("Temperature :" + data[3]);
    Serial.println();
    parsing=false;
    sData= "";
   }
 }

}
