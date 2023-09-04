#include <Arduino.h>
#include "ACS712.h"

#define CURRENT_READ 34

ACS712  ACS(CURRENT_READ, 3.3, 4095, 100);


void setup() {
  Serial.begin(9600);
  ACS.autoMidPoint();
}

void loop() {
  float average = 0;
  uint32_t start = millis();
  for (int i = 0; i < 100; i++)
  {
    //  select sppropriate function
    //  average += ACS.mA_AC_sampling();
    average += ACS.mA_AC(50);
  }
  float mA = average / 100.0;
  uint32_t duration = millis() - start;
  Serial.print("Time: ");
  Serial.print(duration);
  Serial.print("  mA: ");
  Serial.println(mA);

  delay(1000);
}

