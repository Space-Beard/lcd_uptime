#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int days = 0;
int seconds = 0;
int minutes = 0;
int hours = 0;


void setup() {
  // initialize the LCD and set the screen size
  lcd.begin(16, 2);
  lcd.print(String(days) + " days online.");
  lcd.setCursor(0,1);
  lcd.print(String(hours) + ":" + String(minutes) + ":" + String(seconds));

}

void loop() {
  // delay for 1 second and then increase the value of seconds:
  delay(1000);
  seconds = ++seconds;

  // Seconds logic
  switch(seconds){
    case 60:
      seconds = 0;
      minutes = ++minutes;
      break;
    default:
      break;
  }

  // Minutes logic
  switch(minutes){
    case 60:
      minutes = 0;
      hours = ++hours;
      break;
    default:
      break;
  }

  //Hours logic
  switch(hours){
    case 24:
      hours = 0;
      days = ++days;
      break;
    default:
      break;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String(days) + " days online.");
  lcd.setCursor(0,1);
  lcd.print(String(hours) + "h:" + String(minutes) + "m:" + String(seconds) + "s");

}
