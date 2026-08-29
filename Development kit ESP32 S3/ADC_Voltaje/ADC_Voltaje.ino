#define PIN_ANALOG_IN 19

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);

  uint32_t milivoltios = analogReadMilliVolts(PIN_ANALOG_IN);

  float voltajeADC = milivoltios / 1000.0;

  // Divisor 1:4 del shield Freenove
  float alimentacion = voltajeADC * 4.0;

  Serial.print("ADC: ");
  Serial.print(adcVal);

  Serial.print(" | ADC calibrado: ");
  Serial.print(voltajeADC, 3);
  Serial.print(" V");

  Serial.print(" | Alimentacion: ");
  Serial.print(alimentacion, 2);
  Serial.println(" V");

  delay(500);
}