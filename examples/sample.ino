#include<Wire.h>
#include<GroveI2CMiniMorter.h>

GroveI2CMiniMoto morter1(0x62);

void setup() {
  Serial.println("Start morter");
  Wire.begin(); 
}

void loop() {
  Serial.println("Forward!");
  morter1.forwardDrive(50);
  delay(1000);
  Serial.println("Stop!");
  morter1.stop();
  delay(1000);
  Serial.println("Reversal!");
  morter1.reversalDrive(50);
  delay(1000);
  Serial.println("Stop!");
  morter1.stop();
  delay(1000);
}
