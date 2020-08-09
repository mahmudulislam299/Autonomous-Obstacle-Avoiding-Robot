/* Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 * Project: Autonomous Obstacle Avoiding Robot
 */
 
#define inA 4///right
#define inB 5///right
#define inC 6///left
#define inD 7///left
#define ena 9
#define enb 8

#define trigPin1 14 
#define echoPin1 15
#define trigPin2 32 
#define echoPin2 34 
#define trigPin3 41 
#define echoPin3 43

long duration1, distance1, duration2, distance2, duration3, distance3; //1 for forward, 2 for left, 2 for right

void mot_init();



void setup() {
   mtr_strt();
   sonar_strt();
   Serial.begin(9600); // Starts the serial communication
}

void loop() {
  m_distance();
  drive_obstacle();
}

void sonar_strt()
{
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

    pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

    pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
}

void mtr_strt()
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  
  digitalWrite(inA,HIGH);
  digitalWrite(inB,HIGH);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,HIGH);
}

void drive_obstacle(){
  if(distance1>=40 && distance2>= 40 && distance3>= 40)
  {
    _speed(90, 90);//forward
    Serial.println("FORWARD");
  }
  
  else if((distance1<40 && distance1>0 && (distance2 > distance3)) || (distance3<40) && (distance3 < distance2))
  {
   _speed(0, 90); //left//130
   
   Serial.println("LEFT");

  }

  else if((distance1<40 && distance1>0 && (distance2 < distance3)) || (distance2<40) && (distance3 > distance2) )
  {
   _speed(90, 0); //right/130
   
   Serial.println("right");
  } 
}



void _speed(int lm, int rm)       
{
 if(lm==0)                 
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,HIGH);
  }
  if(lm>0)
  {
    digitalWrite(inC,HIGH);        
    digitalWrite(inD,LOW);
  }
  else if(lm<0)
  {
    digitalWrite(inC,LOW);          
    digitalWrite(inD,HIGH);
  }


  if(rm==0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,HIGH);
  }
  if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }
  if(lm>254) lm=254;                
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
  
  analogWrite(ena,abs(rm));         
  analogWrite(enb,abs(lm));         
  
}

void m_distance()
{
  /****************forword sensor************************************/
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin1, HIGH);

  delayMicroseconds(5); //this delay is required as well!
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

  /***************************************************************/
  
  /****************left sensor************************************/
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin2, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

  
  /***************************************************************/
  
  
  /****************right sensor************************************/
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin3, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3/2) / 29.1;

  /***************************************************************/

  
  /*Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");*/
  
  
}
