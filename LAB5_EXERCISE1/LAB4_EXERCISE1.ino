#include <SPI.h>

#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9

int i=0,j=0;

int map7sec[10] = {
  0b00111111,//0
  0b00000110,//1
  0b01011011,//2
  0b01001111,//3
  0b01100110,//4
  0b01101101,//5
  0b01111101,//6
  0b00000111,//7
  0b01111111,//8
  0b01101111//9
  };

void spi_write_1(unsigned char cData)
{
  shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST,cData);
  digitalWrite(SS_PIN_1,HIGH);
  digitalWrite(SS_PIN_1,LOW);
}
void spi_write_2(unsigned char cData)
{
  shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST,cData);
  digitalWrite(SS_PIN_2,HIGH);
  digitalWrite(SS_PIN_2,LOW);
}    
  
  void setup()
{
  pinMode (SS_PIN_1,OUTPUT);
  pinMode (SS_PIN_2,OUTPUT);
  pinMode (DATA_PIN,OUTPUT);
  pinMode (CLOCK_PIN,OUTPUT);
  Serial.begin(9600);
}

void show_num(int x)
{
  int a,b;
  a = x%10;
  b = x/10;
  spi_write_1(map7sec[b]);
  spi_write_2(map7sec[a]); 
}

void loop()
{
  for(int x = 0;x<100;x++)
  { 
     show_num(x);
     delay(1000);
  }
}
