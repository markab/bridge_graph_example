#include <Bridge.h>

unsigned long timer;

void setup() {

  // startup bridge
  Bridge.begin();
  
  // initialise the loop timer
  timer = millis();
}

void loop() {
  
  // loop timer watchdog
  if (timer > millis()) timer = millis();
  
  // every 200ms write 3 random values to the bridge shared storage
  if (millis()-timer > 200) {
    
    timer = millis();
    
    Bridge.put("random1", String(random(1,99)));
    Bridge.put("random2", String(random(1,99)));
    Bridge.put("random3", String(random(1,99)));
  }
}



