#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//atau 0x3F

namespace LCDI2C{
void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("System On");
}
void LCDPrint(String text,int c,int b){
  lcd.setCursor(c,b);
  lcd.print(String(text));
}
void LCDPrintNumber(int text, int c, int b){
  lcd.setCursor(c,b);
  lcd.print(text);
}
}