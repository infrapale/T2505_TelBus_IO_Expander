// Blinks an LED attached to a MCP23XXX pin.

#include <Adafruit_MCP23X17.h>

// uncomment appropriate line
Adafruit_MCP23X17 mcp;

void setup() {
  Serial.begin(9600);
  //while (!Serial);
  Serial.println("MCP23xxx Blink Test!");
  Wire.begin();
  // TWBR = ((F_CPU / frequency) - 16) / 2;
  Wire.setClock(400000L); 
  // uncomment appropriate mcp.begin
  if (!mcp.begin_I2C(0x25,&Wire)) {
    Serial.println("Error.");
    while (1);
  }
  for (uint8_t i=0;i<16;i++)
  {
    mcp.pinMode(i, OUTPUT);
  }

  
  Serial.println("Looping...");
}

void loop() 
{
  mcp.writeGPIOA(0x55);
  mcp.writeGPIOA(0xAA);
  // mcp.writeGPIOAB(0x5555);
  // mcp.writeGPIOAB(0xAAAA);
 
 
  //delay(1000);
  
  
  // mcp.digitalWrite(LED_PIN, HIGH);
  // delay(5);
  // mcp.digitalWrite(LED_PIN, LOW);
  // delay(5);
}