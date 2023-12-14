#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

// Create an instance of the HMC5883L sensor with the custom I2C address
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(0x3C); // Change the address if necessary

void setup(void) {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Initialize the sensor
  if (!mag.begin()) {
    Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    while (1);
  }
}

void loop(void) {
  // Get the latest sensor readings
  sensors_event_t event;
  mag.getEvent(&event);

  // Calculate the heading in degrees
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  if (heading < 0) {
    heading += 2 * PI;
  }
  
  // Convert radians to degrees
  heading = heading * 180 / PI;

  // Print the heading
  Serial.print("Heading: ");
  Serial.println(heading);
  
  delay(100); // Adjust the delay as needed
}
