#define DATA_PIN 5
#define CLOCK_PIN 6
#define LATCH_PIN 4
#define BUTTON1 8
#define BUTTON2 9
int i = 0;
int j = 0;
int data;
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
void setup()
     {           
     pinMode(LATCH_PIN,OUTPUT);
     pinMode(CLOCK_PIN,OUTPUT); 
     pinMode(DATA_PIN,OUTPUT);
     pinMode(BUTTON1,INPUT_PULLUP);
     pinMode(BUTTON2,INPUT_PULLUP);               
     }
void setLed(uint8_t state)
{
     for(i=0;i<8;i++)
     {
       digitalWrite(DATA_PIN,(state>>(7-i))&0x01);
       digitalWrite(CLOCK_PIN,HIGH);
       delay(100);            
       digitalWrite(CLOCK_PIN,LOW);
       delay(100);
     }
       digitalWrite(LATCH_PIN, HIGH);//output Register Clock
       delay(10);
       digitalWrite(LATCH_PIN, LOW);
       delay(10);
}                    
void loop()
     {
   int BUTTOONpull1 = digitalRead(BUTTON1);
   int BUTTOONpull2 = digitalRead(BUTTON2);

   if (BUTTOONpull1==0)
   {
   j++;
   }
   if (BUTTOONpull2==0)
   {
   j--;
   }
   if (j>9)
   {
    j=0; //start at 0
   }
   if (j<0)
   {
    j=9; //start at 9
   }
   setLed(map7sec[j]);
   //delay(100);
    
}
