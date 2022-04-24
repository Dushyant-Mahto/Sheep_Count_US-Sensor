int trig1 = 4, echo1 = 3; 
int trig2 = 9, echo2 = 8; 

int c = 0;  

void setup()
{
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int d1, d2;
  int dst1, dst2;
  int gate = 200;
  
  
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2); 
  
  
  digitalWrite(trig1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1, LOW);  
  d1 = pulseIn(echo1, HIGH);  
  dst1 = 0.034*(d1/2);
  
  
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);  
  d2 = pulseIn(echo2, HIGH);  
  dst2 = 0.034*(d2/2);
  
  if(dst1<gate)
  {
    c++;
    delay(1000);  
  }
  
  if(dst2<gate)
  {
    if(c>0){
      c--;
      delay(1000);
    }  	
  }
  
  Serial.print("Sheeps Inside = ");
  Serial.println(c);
  delay(600);
}