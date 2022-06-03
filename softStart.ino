/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = 1;    // select the input pin for the potentiometer
int ledPin = 0;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int buttonState = 0; //digital
const int buttonPin = 1;//digital
float pwm_v = 0;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = map(sensorValue, 0, 1023, 0, 10);
    pwm_v += voltage;
    if (pwm_v > 100) {
      pwm_v = 100;
    }
    float pwm_real_persen = sqrt((pwm_v/100))*100;// real power I and V
    float out_pwm = map(pwm_real_persen, 0, 100, 0, 255);
    analogWrite(ledPin, out_pwm);


    delay(50);
  } else {
    analogWrite(ledPin, 0);
    pwm_v = 0;
  }
}
