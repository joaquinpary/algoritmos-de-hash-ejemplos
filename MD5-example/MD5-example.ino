#include <MD5.h>

int ledPin = 13;
String inputMessage;

void setup() {
  // Pin 13 Output
  pinMode(ledPin, OUTPUT);
  Serial.begin(57600);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed fo native USB por only
  }
  Serial.println("Enter word:");
}

void loop() {
  // Wait until data is available on the serial port
  if (Serial.available() > 0) {
    inputMessage = Serial.readStringUntil('\n');
    Serial.print("Word:");
    Serial.println(inputMessage);
    unsigned char* hash = MD5::make_hash(inputMessage.c_str());
    
    // Generate the digest (hex enconding) of our hash
    char *md5str = MD5::make_digest(hash, 16);
    
    // Print result
    Serial.print("MD5 Hash: ");
    Serial.println(md5str);
    
    // Free the memory used for digest and hash
    free(md5str);
    free(hash);

    // Pide al usuario otro mensaje
    Serial.println("Enter word:");
  }
}

