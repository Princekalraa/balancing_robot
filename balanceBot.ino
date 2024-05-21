#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2

int ip3=2,ip4=3;


int t=8,e=9;


void setup() {
  pinMode(t,  OUTPUT);  //trigger pin
  pinMode(e, INPUT);  //echo pin
  
  pinMode(ip3,OUTPUT);
  pinMode(ip4,OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  Serial.begin(115200);
}


float distance(){
  
  float  duration, cm;
  
  digitalWrite(t, LOW);
  delayMicroseconds(2);
  digitalWrite(t,  HIGH);
  delayMicroseconds(5);
  digitalWrite(t, LOW);
  
  duration  = pulseIn(e, HIGH);


  cm = duration/ 29 / 2;
  Serial.print("Distance:");
  Serial.println(cm);
  return cm; //returns  distance in centimeters
}


void loop() {
  
  float dis = distance();
  
  analogWrite(E1 ,100);
  analogWrite(E2 ,100);

  if (dis>30){
    
    digitalWrite(ip3,HIGH);
    digitalWrite(ip4,LOW);
  Serial.println("Backward");
  }
  else if(dis<30)
  {
    

    digitalWrite(ip3,LOW);
    digitalWrite(ip4,HIGH);
    Serial.println("Forward");
  }


}