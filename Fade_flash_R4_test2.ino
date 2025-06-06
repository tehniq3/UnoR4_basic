/*
  based on Fade -  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
  Nicu Florica (niq_ro) changed to test on Uno R4 at builtin led (D13)
*/

int led = 13;            // the PWM pin the LED is attached to
int brightness = 0;      // how bright the LED is
int fadeAmount = 5;      // how many points to fade the LED by
int brightnessmax = 255; // max bright of the LED

// the setup routine runs once when you press reset:
void setup() {
  // declare pin to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness >= brightnessmax) {
    fadeAmount = -fadeAmount;
  }
  if (brightness <= 0) {
    fadeAmount = -fadeAmount;
    analogWrite(led, 0);
    delay(100);
    analogWrite(led, brightnessmax);
    delay(100);
    analogWrite(led, 0);
    delay(100);
    analogWrite(led, brightnessmax);
    delay(100);
    analogWrite(led, 0);
  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(50);
} // end main loop
