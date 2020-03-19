const byte LED_pin = 8;
const byte Interrupt_pin = 2;
volatile byte state = LOW;// due to RISING is LOW to HIGH

int i=1;
int a = 1000;

void setup()
{
  pinMode(LED_pin, OUTPUT);
  pinMode(Interrupt_pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(Interrupt_pin), blink, RISING);
}

void loop()
{
  
  digitalWrite(LED_pin, state);
  delay(a);// "a" from loop
  state = !state;//LOW to HIGH
}

void blink()
{
  if (a>3000)
   a=1000;
   a+=1000;
  
}
