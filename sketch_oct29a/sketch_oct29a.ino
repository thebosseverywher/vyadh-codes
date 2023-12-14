/* This example will read all channels from the AS7341 and print out reported values */
// Graph should be of the format wavelength vs absorption % of each wavelength by the object

#include <Adafruit_AS7341.h>

Adafruit_AS7341 as7341;


void setup() {
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
 
  
 

  as7341.setATIME(100);
  as7341.setASTEP(999);
  as7341.setGain(AS7341_GAIN_256X);
}

void loop() {
  // Read all channels at the same time and store in as7341 object
  

  // Print out the stored values for each channel
  unsigned int arr[8];
  //Serial.print("F1 415nm (Violet): ");
  arr[0]=as7341.getChannel(AS7341_CHANNEL_415nm_F1);
  //Serial.print("F2 445nm (Indigo): ");
  arr[1]=as7341.getChannel(AS7341_CHANNEL_445nm_F2);
  //Serial.print("F3 480nm (Blue): ");
  arr[2]=as7341.getChannel(AS7341_CHANNEL_480nm_F3);
  //Serial.print("F4 515nm (Cyan): ");
  arr[3]=as7341.getChannel(AS7341_CHANNEL_515nm_F4);
  //Serial.print("F5 555nm (Green): ");
  arr[4]=as7341.getChannel(AS7341_CHANNEL_555nm_F5);
  //Serial.print("F6 590nm (Yellow): ");
  arr[5]=as7341.getChannel(AS7341_CHANNEL_590nm_F6);
  //Serial.print("F7 630nm (Orange): ");
  arr[6]=as7341.getChannel(AS7341_CHANNEL_630nm_F7);
  //Serial.print("F8 680nm (Red): ");
  arr[7]=as7341.getChannel(AS7341_CHANNEL_680nm_F8);
  
  for (int i = 0; i < 8; i++) {
  /*Serial.print("Channel ");
  Serial.print(i);
  Serial.print(": ");*/
  //Serial.print(100-((float)arr[i]*100/65535));
  Serial.print(arr[i]);

  Serial.print("\t");
}
  /*Serial.println("");
  Serial.print("Clear    : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_CLEAR));

  Serial.print("Near IR  : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_NIR));*/

  Serial.println("");
}