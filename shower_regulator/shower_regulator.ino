const float showerTime = 5; //minutes
const int warmupTime = 20; //seconds

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int stat = 0; //keeps track of the status 

void setup() {
  lcd.begin(16,2); 
  pinMode(13,OUTPUT); //Set pin 13 as output (For solenoid valve)
  pinMode(10,OUTPUT); //Set pin 10 as output (For buzzer)
}

void loop() {
  if(stat == 0){ 
    digitalWrite(13,HIGH); //Open solenoid valve
    tone(10,2000,1000); //Gives the warmup buzzer
    for(int  i = warmupTime; i > 0; i--){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Water Warmup:"); 
      lcd.setCursor(0,1);
      lcd.print(String(i) + " seconds"); 
      delay(1000);
    }
    stat++; //Update status
  }
  if(stat == 1){ //If the status is 1, begin the shower timer
    tone(10,2000,1000); //Gives the shower buzz; warmup is over
    delay(1500);
    tone(10,2000,1000);
    for(int i = showerTime * 60; i > 0; i--){
      if(i == 120){ //If there are 2 minutes left, give a warning buzz
        tone(10,2000,1000); 
      }else if(i == 60){ //If there is 1 minute left, give a second warning buzz
        tone(10,2000,1000);
      }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Shower:"); 
      lcd.setCursor(0,1);
      lcd.print(String(i) + " seconds"); 
      delay(1000);
    }
    stat++; //Update status
  }
  if(stat == 2){ //If the status is 2,stop the shower and notify user that it is over
    digitalWrite(13,LOW); //Close solvenoid valve
    tone(10,2000); //Gives buzz until it is shut off
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Shower Over");
    lcd.setCursor(0,1);
    lcd.print("Have a Good Day!"); 
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Turn me off"); 
    lcd.setCursor(0,1);
    lcd.print("Turn water off"); 
    delay(5000);  
  }
}