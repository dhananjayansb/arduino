#define trigPin 13
#define echoPin 12
#define buzzer 6

void setup()
{
  pinMode(trigPin, OUTPUT); //Set pin 13 as output (For Ultrasonic sensor - Trigger)
  pinMode(echoPin, INPUT); //Set pin 12 as input (For Ultrasonic sensor - Echo)
  pinMode(buzzer,OUTPUT); //Set pin 6 as output (For buzzer)

}

void loop()
{
  long duration, distance;

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1; //Calculate the distance in cm

  if (distance < 100) //When the the distance below 100cm, you can change the value
  { 
    digitalWrite(motor,HIGH); 
    digitalWrite(buzzer,HIGH);
  } 

  else //When greater than 100cm
  {
    digitalWrite(motor,LOW);
    digitalWrite(buzzer,LOW); 
  } 

  delay(500);

}