/*
This app can use page with DHT
* - create 4 pages
* - use 2 buttons
* - use LCD: LiquidCrystal 16x2
* - DHT 11
* - wires
*/

#include <LiquidCrystal.h>
#include <dht.h>

const int rs=12, en=11, d4=A0, d5=A1, d6=A2, d7=A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;

#define DHT11_PIN A4 // Sensor DHT11 pin A4 
#define ButtIncrement 9 // Button increment page ==> pin 9
#define Buttdecrement 8 // Button decrement page ==> pin 8
// Number of page |   Count page ==> from 0 ot 5
int numpage = 0, countpage = 5;
long t=0, duration = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(ButtIncrement, INPUT_PULLUP);
  pinMode(Buttdecrement, INPUT_PULLUP);
  t=millis();

}

void loop() {
  duration=millis()-t;
 

  Buttons();
  Pages();

  if(duration >= 1000){
     int value = DHT.read11(DHT11_PIN); // Get value from DHT11
     t=millis();
  }
}

void Buttons(){

  if (digitalRead(ButtIncrement) == LOW){
    delay(200);
    lcd.clear();
    numpage++;
    if (numpage > countpage) numpage = countpage;
    delay(100);
  }

  if (digitalRead(Buttdecrement) == LOW){
    delay(200);
    lcd.clear();
    numpage--;
    if(numpage < 0) numpage = 0;
    delay(100);
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

void HomePage(){
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  lcd.setCursor(0, 1);
  lcd.print("Main App~ DHT");
}

void Page1(){
  ShowNotData();
  ShowCounters();
}

void Page2(){
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");

  ShowCounters();
}

void Page3(){
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.setCursor(0, 1);
  lcd.print(DHT.humidity);
  lcd.print("%");

  ShowCounters();
}

void Page4(){
  ShowNotData();
  ShowCounters();
}

void Page5(){
  ShowNotData();
  ShowCounters();
}

void ShowCounters(){

  lcd.setCursor(15, 1);
  lcd.print(countpage);
  lcd.setCursor(14, 1);
  lcd.print("/");
  lcd.setCursor(13, 1);
  lcd.print(numpage);
}

void ShowNotData(){
    lcd.setCursor(0, 0);
    lcd.print("No Data!");
}