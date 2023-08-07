/*
This app can use page with DHT
* - create 4 pages
* - use 2 buttons
* - use LCD: LiquidCrystal 16x2
* - DHT 11
* - wires
*/

#include <LiquidCrystal.h>
const int rs=12, en=11, d4=A0, d5=A1, d6=A2, d7=A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ButtIncrement 9 // Button increment page ==> pin 9
#define Buttdecrement 8 // Button decrement page ==> pin 8
// Number of page |   Count page ==> from 0 ot 5
int numpage = 0, countpage = 5;
void setup() {
  lcd.begin(16, 2);
  pinMode(ButtIncrement, INPUT_PULLUP);
  pinMode(Buttdecrement, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void Buttons(){
  if (digitalRead(ButtIncrement) == LOW){
    delay(200);
    lcd.clear();
    numpage++;
  }
}
void Pages(){

  switch (numpage){

    case 0:
    HomePage();
    break;

    case 1:
    Page1();
    break;

    case 2:
    Page2();
    break;

    case 3:
    Page3();
    break;

    case 4:
    Page4();
    break;

    case 5:
    Page5();
    break;
  }
}
