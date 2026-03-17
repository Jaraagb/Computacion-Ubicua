// Lectura de temperatura y humedad con DHT22 y envío por serial

#include <DHT.h>
#include <DHT_U.h>

const int pinDHT = 2;
const int tipoDHT = DHT22;

DHT dhtSensor(pinDHT, tipoDHT);

// Función que obtiene los valores del sensor
bool obtenerLecturas(float &temperatura, float &humedad) {
  temperatura = dhtSensor.readTemperature();
  humedad = dhtSensor.readHumidity();

  if (isnan(temperatura) || isnan(humedad)) {
    return false;
  }

  return true;
}

// Función que imprime los datos en el monitor serial
void imprimirDatos(float t, float h) {
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" C | Hum: ");
  Serial.print(h);
  Serial.println(" %");
}

void setup() {
  Serial.begin(9600);
  dhtSensor.begin();
}

void loop() {
  float tempLeida, humLeida;

  bool lecturaValida = obtenerLecturas(tempLeida, humLeida);

  if (lecturaValida) {
    imprimirDatos(tempLeida, humLeida);
  } else {
    Serial.println("Fallo en la lectura del DHT22");
  }

  delay(500);
}