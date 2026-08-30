#include "FS.h"
#include "SD_MMC.h"

#define SD_MMC_CMD 38
#define SD_MMC_CLK 39
#define SD_MMC_D0  40

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Iniciando tarjeta SD...");

  SD_MMC.setPins(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0);

  if (!SD_MMC.begin("/sdcard", true)) {
    Serial.println("ERROR: No se pudo montar la tarjeta SD.");
    return;
  }

  uint8_t cardType = SD_MMC.cardType();

  if (cardType == CARD_NONE) {
    Serial.println("ERROR: No se detecto ninguna tarjeta SD.");
    return;
  }

  Serial.print("Tipo de tarjeta: ");

  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("DESCONOCIDO");
  }c:\Users\Nano\Desktop\Git Hub\ESP32\Development kit ESP32 S3\Freenove_Development_Kit_for_ESP32_S3-main\Sketches\Sketch_02_WS2812\Sketch_02_WS2812.ino

  uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);

  Serial.print("Capacidad: ");
  Serial.print(cardSize);
  Serial.println(" MB");

  File archivo = SD_MMC.open("/prueba.txt", FILE_WRITE);

  if (!archivo) {
    Serial.println("ERROR: No se pudo crear prueba.txt");
    return;
  }

  archivo.println("Hola desde mi ESP32-S3 Freenove.");
  archivo.println("Esta linea fue escrita en la tarjeta SD.");
  archivo.close();

  Serial.println("Archivo prueba.txt creado.");

  archivo = SD_MMC.open("/prueba.txt");

  if (!archivo) {
    Serial.println("ERROR: No se pudo abrir prueba.txt.");
    return;
  }

  Serial.println();
  Serial.println("Contenido del archivo:");

  while (archivo.available()) {
    Serial.write(archivo.read());
  }

  archivo.close();

  Serial.println();
  Serial.println("Prueba terminada correctamente.");
}

void loop() {
}