//Simple Capacitance sensor with Vallman VMA 203
#include <LiquidCrystal.h>
#include <Capacitor.h>
Capacitor cap1(2,A2);  //D2, A2
// VMA uses A0, 4-9 digital pins
// MFG, Vellman says this thing is for a MEGA, but it works fine on an UNO
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(){
 lcd.begin(16, 2);              // Configure the LCD
 lcd.setCursor(0,0);
 lcd.print("CAPACITANCE");    
 Serial.begin(115200);
 //LiquidCrystal wont let me check for init. IDK, figure that out later.
 //  lcd.setBacklight(HIGH);  // no member function lame.
  lcd.print("CAPACITANCE");
}
 
void loop(){
  float CPM = cap1.Measure(); //Cin pF
  if(CPM<1){
    Serial.println("No Connection");
    lcd.setCursor(0,1);
    lcd.print("NOT CONNECTED");
    }
  if(CPM < 1000 && CPM >= 1){
    Serial.print(CPM);
    Serial.println("pF");
    lcd.setCursor(0,1);
    lcd.print(CPM);
    lcd.setCursor(6,1);
    lcd.print("  pF   ");
    }
  if(CPM >= 1000 && CPM < 1000000){
    Serial.print(CPM);
    Serial.println("nF");
    lcd.setCursor(0,1);
    lcd.print(CPM);
    lcd.setCursor(6,1);
    lcd.print("  nF   ");
    }
  if(CPM >= 1000000){
    Serial.print(CPM);
    Serial.println("uF");
    lcd.setCursor(0,1);
    lcd.print(CPM);
    lcd.setCursor(6,1);
    lcd.print("  uF   ");
    }  
    delay(800); //slow down lcd screen latency
  }
