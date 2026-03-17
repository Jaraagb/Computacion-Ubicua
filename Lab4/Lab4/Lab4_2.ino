// Sensor de temperatura con visualización de promedio en LCD

#include <LiquidCrystal.h>

const int pinTemp = A0;
const int cantidadMuestras = 5;

// Inicialización de la pantalla
LiquidCrystal pantallaLCD(7, 6, 5, 4, 3, 2);

// Función para obtener la temperatura desde el sensor
float obtenerTempSensor() {
  int datoADC = analogRead(pinTemp);
  float milivoltios = datoADC * (5000.0 / 1023.0);
  float tempCalculada = (milivoltios / 10.0) - 50.0;
  return tempCalculada;
}

// Función que calcula el promedio de varias lecturas
float promedioLecturas() {
  float suma = 0.0;

  int contador = 0;
  while (contador < cantidadMuestras) {
    suma += obtenerTempSensor();
    contador++;
    delay(500);
  }

  return suma / cantidadMuestras;
}

// Función encargada de imprimir en la pantalla
void imprimirLCD(float valorTemp) {
  pantallaLCD.clear();

  pantallaLCD.setCursor(0, 0);
  pantallaLCD.print("Temp promedio:");

  pantallaLCD.setCursor(0, 1);
  pantallaLCD.print(valorTemp, 1);
  pantallaLCD.print(" C");
}

void setup() {
  pantallaLCD.begin(16, 2);
}

void loop() {
  float tempProm = promedioLecturas();
  imprimirLCD(tempProm);
}