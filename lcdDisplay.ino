#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
SoftwareSerial mySerial(2, 4); // RX, TX


void setup() {
  // Open serial communications:
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  Display_Text( 0, "Welcome Delphi.." );
  
  // The HC-06 defaults to 9600 according to the datasheet.
  mySerial.begin(57600);
}

void loop() {

}

void Display_Text( int LineNo,  String dText ) {
     //lcd.clear();  
     switch( LineNo ){
       case 0 : lcd.setCursor(0, 0); break; 
       case 1 : lcd.setCursor(0, 1); break;       
     }
     lcd.print( dText );  
          
     int space = 16 - dText.length();     
     for( int i = space; i<= 16;  i++ )  lcd.print(" ");  // 여백 채움.
}