#include <AESLib.h>

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  uint8_t key[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  char data[] = "0123456789012345"; //16 chars == 16 bytes
  aes128_enc_single(key, data);
  Serial.print("encrypted: ");
  Serial.println(data);
  aes128_dec_single(key, data);
  Serial.print("decrypted: ");
  Serial.println(data);
  digitalWrite(ledPin, LOW);
  delay(500);
}

