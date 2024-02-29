#include <Arduino.h>
#include <Wire.h> 
#include <DS18B20.h>
#include "LCDI2C.h"

// DS18B20 ds(3);
 
// int TurbidityPin = A1;
// int pHPin = A2;


// float volt;
// float ntu;
// float adcPH,TeganganPh,PH_step,pHValue;


float sendturbidity,sendph,sendTemp;

// float PH4 = 3.02;
// float PH7 = 2.58;
// int Vo;

// // put function declarations here:
// float round_to_dp( float in_value, int decimal_place )
// {
//   float multiplier = powf( 10.0f, decimal_place );
//   in_value = roundf( in_value * multiplier ) / multiplier;
//   return in_value;
// } 

// float getdataTurbidity(){
//     volt = 0;
//     for(int i=0; i<800; i++)
//     {
//         volt += ((float)analogRead(TurbidityPin)/1023)*5;
//     }
//     volt = volt/800;
//     volt = round_to_dp(volt,2);
//     if(volt < 2.5){
//       ntu = 3000;
//     }else{
//       ntu = -1120.4*square(volt)+5742.3*volt-4353.8; 
//     }
//     return ntu;
// }

// float getdataPH(){
//     adcPH = analogRead(pHPin); //menggunakan pin A0 untuk membaca output sensor pH
//     TeganganPh = (5.0 / 1024.0) * adcPH;
//     PH_step = (PH4 - PH7) / 3;
//     pHValue = 7+ ((PH7 - TeganganPh) / PH_step);
//     return pHValue;
// }


// float getTemp(){
//     //Vo = analogRead(ThermistorPin);
//     Vo = ds.getTempC();

//     return Vo;
// }
void setup() {
    // pinMode(TurbidityPin,INPUT);
    // pinMode(pHPin,INPUT);
    // LCDI2C::setup(); //Inisialisasi LCD
    Serial.begin(115200);
}

void loop() {

  sendturbidity= 100;
  sendph=200;
  sendTemp=500;
  Serial.println("#"+String(sendph)+"#"+String(sendturbidity)+"#"+String(sendTemp)+"#$");
  
  // lcd.setCursor(0,0);
  // lcd.print("NTU: " + String(sendturbidity));
  // lcd.setCursor(0,1);
  // lcd.print("pH:" + String(sendph));
  // lcd.setCursor(10,1);
  // lcd.print("T:" + String(sendTemp));

  delay(500);
}

