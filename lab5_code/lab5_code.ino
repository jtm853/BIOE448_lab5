const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
    // put your main code here
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCm = duration/pow(10, 6) * 34300/2;
  distanceInch = duration/pow(10,6) * 13504/2;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/ ");
  Serial.print(distanceInch);
  Serial.println(" in");

  if (distanceCm < 6){
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  }

  delay(1000);
}