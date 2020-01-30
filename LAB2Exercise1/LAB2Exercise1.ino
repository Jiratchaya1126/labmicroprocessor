#define DATA_PIN 11
#define CLOCK_PIN 13
#define LATCH_PIN 10

int i = 0;
int data;
bool toggle;
void setup()
{
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}
void loop()
{
  data = 0b1000000000000000;
  //digitalWrite(LATCH_PIN, LOW);
  for(i=0;i<16;i++)
  {
    digitalWrite(DATA_PIN,data>>(15-i)&0x01); //DATA pin เลื่อนไปทั้งหมดเลยให้ตัวสุดท้ายเป็น1
    //digitalWrite(DATA_PIN,toggle);
    digitalWrite(CLOCK_PIN,HIGH);
    delay(100);
    digitalWrite(CLOCK_PIN,LOW);
    delay(100);
    //toggle=!toggle;
   digitalWrite(LATCH_PIN, HIGH);//output Register Clock
  //toggle=!toggle;
   delay(100);
   digitalWrite(LATCH_PIN, LOW);
   delay(100);
  }
}
  
