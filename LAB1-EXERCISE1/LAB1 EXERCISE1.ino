//EXERCISE1
//void setup()
//{
  //DDRD = 0b11111100;
  //DDRB = 0b000011;
//}
//void loop()
//{
  //PORTB = 0b000010;
  //delay(500);
  //for(int i=0;i<2;i++)
  //{
  //PORTB=PORTB>>1;
  //delay(500);
  //}
  //PORTD = 0b10000000;
  //delay(500);
  //for(int i=0;i<8;i++)
  //{
  //PORTD=PORTD>>1;
  //delay(500);
  //}
//}


//EXERCISE2
unsigned int a=0x01;
void setup()
{
  DDRD = 0b11111111;
  DDRB = 0b11111111;
}
void loop()
{
  PORTD=a;
  delay(500);
  if(PINB==0x00000001)
  a=a<<1;
  if(PINB==0b00000010)
  a=a>>1;
}
