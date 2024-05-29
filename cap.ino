#include <Adafruit_LiquidCrystal.h>
#include <Capacitor.h>
Capacitor cap1(7,A2);

int X1,C; //resistance value
byte  f_ic, xp;
char R1_str[3];
char R_str[4];
float tau1;   
unsigned long T1, T2, tau;
void Pomiar_C();


Adafruit_LiquidCrystal lcd(0); //i2c lcd init

void setup() {
  //using adafruit i2c Lcd
  Serial.begin(115200);
 
    // set up the LCD's number of rows and columns:
  if (!lcd.begin(16, 2)) {
    Serial.println("Could not init backpack. Check wiring.");
    while(1);
  }
  Serial.println("Backpack init'd.");
  lcd.setBacklight(HIGH);  
  //not working with this module, maybe test the lcd, or try it with an lcd known to have a bk light
   lcd.print("CAPACITANCE");
}

void loop() {
 Serial.println(cap1.Measure());  // Measure the capacitance (in pF), print to Serial Monitor
 delay(1000); 
  Pomiar_C();
}

void Pomiar_C(){
  Cyfry();
  char C_str[4];
  sprintf(C_str,"%d", X1);
  lcd.setCursor(0,1);
     
     if (f_ic > 6) { 
        lcd.setCursor(8,1);
        lcd.print("uF"); //symbol u
        lcd.setCursor(0,1);
     }   
     if (f_ic < 7) {
        lcd.setCursor(8,1);
        lcd.print("nF"); //symbol n
        lcd.setCursor(0,1);
      }
     if (f_ic < 4) {
        lcd.setCursor(8,1);
        lcd.print("pF"); //symbol p
        lcd.setCursor(0,1);
      }
     if (f_ic == 1 or f_ic == 4 or f_ic == 7) {
        // u8g2.drawStr(28, 52, "."); 
        // u8g2.drawStr(40, 52, R1_str); 
        lcd.print(R1_str);
     } 
  delay(500);
}

void Cyfry(){
//  if (P1 == LOW) {tau1 = tau/2.329;}    
//  if (P2 == LOW) {tau1 = tau/350;}
// if (P3 == LOW) {tau1 = cap1.Measure();}


 tau1 = cap1.Measure();
  //obliczenie ilości cyfr wartości
  if (tau1 >= 1 && tau1 <10) {                  
     X1 = tau1;
     int X2 = 10 * (tau1 - X1);
  sprintf(R1_str,"%d", X2);
     f_ic = 1;
     xp = 10;     
  }
  if (tau1 >= 10 && tau1 <100) {            
     X1 = tau1;
     f_ic = 2;
     xp = 32;
  }
  if (tau1 >= 100 && tau1 <1000) {         
     X1 = tau1;
     f_ic = 3;
     xp = 10;
  }
  if (tau1/1000 >= 1 && tau1/1000 <10) {        
     X1 = int(tau1/1000);
     f_ic = 4;
     xp = 10;
     int X2 = 10 * (tau1/1000 - X1);
   sprintf(R1_str,"%d", X2);
  }
  if (tau1/10000 >= 1 && tau1/10000 <10) {      
     X1 = int(tau1/1000);
     f_ic = 5;
     xp = 32;
  }
  if (tau1/100000 >= 1 && tau1/100000 <10) {    
     X1 = int(tau1/1000);
     f_ic = 6;
     xp = 10;
  }
  if (tau1/1000000 >= 1 && tau1/1000000 <10) {  
     X1 = int(tau1/1000000);
     f_ic = 7;
     xp = 10;
     
     int X2 = 10 * (tau1/1000000 - X1);
   sprintf(R1_str,"%d", X2);
  }
   if (tau1/10000000 >= 1 && tau1/10000000 <10) {  
     X1 = int(tau1/1000000);
     f_ic = 8;
     xp = 30;
   }
} 
