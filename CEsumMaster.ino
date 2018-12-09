#include <Wire.h>




//all the pijns that are being analyzed
int inPins[5] = {A0, A1, A2, A3, A4};
int pins[5];

//the data to be transferred to the slave arduino
int masterType = 0, masterX = 0, masterY = 0;

void setup()
{
  for (int i = 0; i < 5; i++) pinMode(inPins[i], INPUT);
  Serial.begin(9600);  
}

void loop()
{
  for (int i = 0; i < 5; i++) 
  {
    //divide the value to 'dull' the numbers and make them easier to match (because of floor division)
    pins[i] = analogRead(inPins[i])/70;
    //Serial.print(pins[i]);
    //Serial.print("   ");
  }
  //Serial.print('\n');
  delay(100);
  if (pins[0] == 2 && pins[1] == 4 && pins[2] == 4 && pins[3] == 4 && pins[4] == 5 ) Serial.write('A');
  if (pins[0] == 3 && pins[1] == 7 && pins[2] == 6 && pins[3] == 6 && pins[4] == 4 ) Serial.write('B');
  if (pins[0] == 2 && pins[1] == 6 && pins[2] == 5 && pins[3] == 5 && pins[4] == 5 ) Serial.write('C');
  if (pins[0] == 2 && pins[1] == 4 && pins[2] == 3 && pins[3] == 6 && pins[4] == 5 ) Serial.write('D');
  if (pins[0] == 2 && pins[1] == 4 && pins[2] == 4 && pins[3] == 4 && pins[4] == 4 ) Serial.write('E');
  if (pins[0] == 3 && pins[1] == 7 && pins[2] == 6 && pins[3] == 4 && pins[4] == 5 ) Serial.write('F');
}




/*hand symbols
 * 
 * A = 2 4 4 4 5
 * B = 3 7 6 6 5
 * C = 2 5 4 4 5
 * D = 2 4 4 5 5
 * E = 2 4 4 4 4
 * F = 3 7 6 4 5
 */
