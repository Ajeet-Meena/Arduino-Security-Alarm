
const int buttonPin = 2;    
const int ledPin = 13; 
const int ledpin2=4;
int ledState = LOW;        
int buttonState;             
int lastButtonState = LOW;   
long lastDebounceTime = 0;  
long debounceDelay = 50;   
const int ldrpin = 0; 
int k=0;
int val=0;
void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ldrpin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
   
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
 
    if (reading != buttonState) {
      buttonState = reading;

     
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  
  

  lastButtonState = reading;
  if(reading==HIGH)
  {
    k=taketime();
    Serial.println(k);
    if(k==1)
    {
      ldrcheck();
      delay(2000);
    }
    
  }
}
int taketime()
{
  
  
    Serial.println("Take Time OK");
    for(int i=0;i<=2;i++)
    {
      digitalWrite(ledpin2,HIGH);
      delay(500);
      digitalWrite(ledpin2,LOW);
      delay(500);
    }
    return 1;

}

void ldrcheck()
{
  Serial.println("LDR check OK");
  while(digitalRead(buttonPin)==LOW)
  {
    val=analogRead(ldrpin);
    val=constrain(val,100,700);
    val=map(val,100,700,0,1023);
    if(val>=500)
    alarm();
    
    Serial.println(val);
    delay(50);
    if(digitalRead(buttonPin)==HIGH)
    {
      break;
    }
  }
}
void alarm()
{
  while(digitalRead(buttonPin)==LOW)
  {
  digitalWrite(ledPin,HIGH);
  if(digitalRead(buttonPin)==HIGH)
  {
  digitalWrite(ledPin,LOW);  
  break;
  }
  
  }
}  

    
  

  
  

