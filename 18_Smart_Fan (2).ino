/***********************************************************
Project 18: Smart Fan
Description: When an object comes in front of it, it detects and fan starts rotating
Company: Texoham eLearning Platform
Website: www.texoham.com/elearning
***********************************************************/

const int trigPin = 10;               //arduino 10th pin connected to trig Pin of the ultrasonic sensor
const int echoPin = 11;               //arduino 11th pin connected to echo Pin of the ultrasonic sensor

//const int Input1 = 3;                 //arduino 3rd pin connected to L293D pin input1
//const int Input2 = 4;                 //arduino 4th pin connected to L293D pin input2
const int Input3 = 8;                 //arduino 8th pin connected to L293D pin input3
const int Input4 = 9;  
const int EN2 = 2 ;//arduino 9th pin connected to L293D pin input4

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (Input4, OUTPUT);
  pinMode (Input3, OUTPUT);
  pinMode (EN2,OUTPUT);
  //pinMode (Input2, OUTPUT);
  //pinMode (Input1, OUTPUT);
  Serial.begin(9600);
}
long duration, distance;
void stop()
{
  digitalWrite(Input4, LOW); 
  digitalWrite(Input3, LOW); 
  digitalWrite(EN2, HIGH);
  //digitalWrite(Input2, LOW); 
  //digitalWrite(Input1, LOW);
}

void start()
{
  digitalWrite(Input4, HIGH); 
  digitalWrite(Input3, LOW); 
  digitalWrite(EN2, HIGH);
  //digitalWrite(Input2, HIGH); 
  //digitalWrite(Input1, LOW);
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;   // The speed of sound is 340 m/s or 29 microseconds per centimeter.// The echo travels out and back, so to find the distance of the
  Serial.println(distance);                                        // object we take half of the distance travelled.
  Serial.println("distance: ");
                                          
  if(distance<20)
  {      
    start();
    delay(500);
  }
  else
  {
    stop();
    delay(500);
  }
}
