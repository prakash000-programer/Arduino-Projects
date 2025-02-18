#include <SoftwareSerial.h>

SoftwareSerial sim808(7, 8); // RX, TX

void setup() {
    Serial.begin(9600);
    int baudRates[] = {9600, 19200, 38400, 57600, 115200};
    
    for (int i = 0; i < 5; i++) {
        sim808.begin(baudRates[i]);
        Serial.print("Testing baud: ");
        Serial.println(baudRates[i]);
        
        sim808.println("AT");
        delay(1000);

        if (sim808.available()) {
            Serial.println("✅ Correct baud rate found!");
            break;
        }
    }
}

void loop() {
    if (sim808.available()) {
        Serial.write(sim808.read());
    }
}
