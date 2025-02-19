#include <ArduinoBLE.h>

BLEService newService("180A"); // creating the service
BLEByteCharacteristic readChar("2A57", BLERead);
BLEByteCharacteristic writeChar("2A58", BLEWrite);

const int trigPin = 8;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  while(!Serial);
    if (!BLE.begin()){
      Serial.println("waiting for ArduinoBLE");
      while(1);
    }

  BLE.setLocalName("Ai and Johnny");
  BLE.setAdvertisedService(newService);
  newService.addCharacteristic(readChar);
  newService.addCharacteristic(writeChar);
  BLE.addService(newService);

  readChar.writeValue(0);
  writeChar.writeValue(0);

  BLE.advertise();
  Serial.println("Bluetooth device active");
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

  readChar.writeValue(distanceCm);


  delay(1000);
}