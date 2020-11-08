 #ifdef __cplusplus
  extern "C" {
 #endif

uint8_t temprature_sens_read();

#ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();
void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.print("Temperature: ");
  Serial.print((temprature_sens_read() - 32) / 1.8);
  Serial.println(" C");
  delay(1000);
}
