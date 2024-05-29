#include <Adafruit_LiquidCrystal.h>
#include <Capacitor.h>
Capacitor cap1(7,A2);  //both are 6th pin in from usb conector using an arduino nano

Adafruit_LiquidCrystal lcd(0); //i2c lcd init
void setup() {
  //using adafruit i2c Lcd
  Serial.begin(115200);
    // set up the LCD's number of rows and columns:
  if (!lcd.begin(16, 2)) {
    Serial.println("Could not init LCD. Check wiring.");
    while(1);
  }
  Serial.println("Backpack init'd.");
  lcd.setBacklight(HIGH);  
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
    delay(500); //slow down
  }
