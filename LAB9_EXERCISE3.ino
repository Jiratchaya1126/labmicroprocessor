#include <SPI.h>
#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
volatile int timer_counter = 0;
int a=0;
int map7sec[10] = 
{
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
  
  void setup()
{
  noInterrupts(); 
  TCCR1A = 0;
  TCCR1B = 0; 
  TCNT1 = timer_counter;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();    
  pinMode (SS_PIN_1,OUTPUT);
  pinMode (DATA_PIN,OUTPUT);
  pinMode (CLOCK_PIN,OUTPUT);
}

void loop()
{
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer_counter;
  a += 1;
  if(a>10)
  a=0;
  spi_write_1(map7sec[a]);
}
