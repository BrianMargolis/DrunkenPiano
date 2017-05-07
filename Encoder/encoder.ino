/////////////////////////////////////////////////////////////////
// Based off of code by Michael Gurevich, Oct. '13
// Modified by Brian Margolis and Bailey Bjornstad, May '17
/////////////////////////////////////////////////////////////////


int numSensors = 3;
void setup() {
  Serial.begin(115200);
}

void loop() {
  sendSignal();
  delay(10);
}

void sendSignal() {
  int readings[numSensors];
  Serial.write(255);	               // send separator byte

  for (int i = 0; i < numSensors; i++) {
    readings[i] = analogRead(i);     // read the value of analog pin i
    Serial.write(readings[i] >> 3);  // send 7 MSB as serial data
    Serial.write(readings[i] & 7);	 // send 3 LSB as serial data
  }

}






