#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial mySerial(13, 12);
int incoming = 0;
int incoming1 = 0;

int pins[7]={8,7,6,5,4,3,2};

byte numbers[10] = { B11111100, B01100000, B11011010, B11110010, B01100110,
B10110110, B10111110, B11100000, B11111110, B11100110};


void setup() {
  Serial.begin(9600);
  for(int i=0;i<7;i++)
    pinMode(pins[i],OUTPUT);
  mySerial.begin(9600);
}
 int number = 0;

void loop() {
  if (Serial.available() == 2){
    int numb = Serial.parseInt();
    int first=numb/10;
    int second=numb%10;
    mySerial.write(second);
    for(int i=0;i<10;i++)
    {
      if (first==i){
        number = i;
        showNumber(number);
      }
    }
}
}
void showNumber(int f)
{
  for(int i=0;i<7;i++)
  {
    if(bitRead(numbers[f],7-i)==HIGH)
    digitalWrite(pins[i],HIGH);
    else 
    digitalWrite(pins[i],LOW);
  } 
}
