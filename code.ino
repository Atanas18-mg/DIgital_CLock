  //Real time clock libraries
  #include <Wire.h> 
  #include <DS3231.h>
  //Liquid crystal library
  #include <LiquidCrystal.h>
  
  //initialize Real time clock modul
  RTClib rtcClock;
  DS3231 rtcFunctons;
  
  // initialize the library by associating any needed LCD interface pin
  // with the arduino pin number it is connected to
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  Wire.begin();
  delay(500);
  lcd.begin(16,2);
  lcd.print("Welcome");

  delay(5000);
}

void loop() 
{
  lcd.clear();
  
  DateTime now = rtcClock.now();

  //print day of the week
  int dayOfWeek = rtcFunctons.getDoW();
  switch(dayOfWeek){
    case 1: 
      lcd.print("Monday");
      break;
    case 2: 
      lcd.print("Tueday");
      break;
    case 3: 
      lcd.print("Wednesday");
      break;
    case 4: 
      lcd.print("Thurstday");
      break;
    case 5: 
      lcd.print("Friday");
      break;
    case 6: 
      lcd.print("Saturday");
      break;
    case 7: 
      lcd.print("Sunday");
      break;
    }

  //print Temperature
  lcd.setCursor(10,0);
  lcd.print(rtcFunctons.getTemperature(), 1);
  lcd.print("C");

  //print time
  lcd.setCursor(0,1);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);

  //print date
  lcd.setCursor(9,1);
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  //print last 2 digits of year
  int year = now.year();
  int last2digits = year%100;
  lcd.print(last2digits);
    
  delay(1000); 
}
