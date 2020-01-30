//EXERCISE2
unsigned int a=0x01;
void setup()
{
  DDRD = 0xFF;
  DDRB = 0xFF;
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
