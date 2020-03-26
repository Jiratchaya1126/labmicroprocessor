#define MOTOR_D1_PIN 7 //input2
#define MOTOR_D2_PIN 8 //input1
#define MOTOR_PWM_PIN 6 //Enable1
int interruptChannelAPin = 2;
int interruptChannelBPin = 3;
bool A_read;
bool B_read;
volatile int encodercount = 0;
//volatile int encoderBcount = 0;

int count = 0;
int direction;

void setup()
{
  pinMode(MOTOR_D1_PIN,OUTPUT);
  pinMode(MOTOR_D2_PIN,OUTPUT);
  pinMode(MOTOR_PWM_PIN,OUTPUT);
  
  pinMode(interruptChannelAPin,INPUT_PULLUP);
  pinMode(interruptChannelBPin,INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(interruptChannelAPin),
                  ChannelA_callback,RISING);
  attachInterrupt(digitalPinToInterrupt(interruptChannelBPin),
                  ChannelB_callback,RISING);
  Serial.begin(9600);
}
void moveForward(int a)
{
  digitalWrite(MOTOR_D1_PIN,HIGH);
  digitalWrite(MOTOR_D2_PIN,LOW);
  analogWrite(MOTOR_PWM_PIN,a);
  direction =1;
}
void moveBackward(int a)
{
  digitalWrite(MOTOR_D1_PIN,LOW);
  digitalWrite(MOTOR_D2_PIN,HIGH);
  analogWrite(MOTOR_PWM_PIN,a);
  direction =0;
}
void loop()
{
   //moveBackward(255);
   moveForward(255);
   Serial.print("Direction : ");
   Serial.print(direction);
   Serial.print(" Position : ");
   Serial.println(encodercount);
   delay(500);
}
void ChannelA_callback()
{
  bool A2_read = digitalRead(interruptChannelBPin);
  if((A_read==0)&&(A2_read==1))
   encodercount--;
}
void ChannelB_callback()
{
  bool B2_read = digitalRead(interruptChannelAPin);
  if((B_read==0)&&(B2_read==1))
  encodercount++;
}
