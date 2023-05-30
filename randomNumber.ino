#include <SevSeg.h>

const int buttonPin = 2;   // Pin conectado al botón
const int displayPin1 = 3; // Pin conectado al segmento A del display
const int displayPin2 = 4; // Pin conectado al segmento B del display
const int displayPin3 = 5; // Pin conectado al segmento C del display
const int displayPin4 = 6; // Pin conectado al segmento D del display
const int displayPin5 = 7; // Pin conectado al segmento E del display
const int displayPin6 = 8; // Pin conectado al segmento F del display
const int displayPin7 = 9; // Pin conectado al segmento G del display

SevSeg sevseg;             // Objeto de la biblioteca SevSeg

int buttonState = 0;       // Variable para almacenar el estado del botón
int randomNumber = 0;     // Variable para almacenar el número aleatorio generado

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del botón como entrada con resistencia pull-up

  // Configurar los pines del display como salida
  pinMode(displayPin1, OUTPUT);
  pinMode(displayPin2, OUTPUT);
  pinMode(displayPin3, OUTPUT);
  pinMode(displayPin4, OUTPUT);
  pinMode(displayPin5, OUTPUT);
  pinMode(displayPin6, OUTPUT);
  pinMode(displayPin7, OUTPUT);

  byte numDigits = 1;      // Número de dígitos en el display (en este caso, solo se muestra un dígito)
  byte digitPins[] = {displayPin1, displayPin2, displayPin3, displayPin4, displayPin5, displayPin6, displayPin7}; // Pines de los segmentos del display
  byte segmentPins[] = {displayPin7, displayPin6, displayPin5, displayPin4, displayPin3, displayPin2, displayPin1}; // Pines de los dígitos del display
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins); // Inicializar el objeto SevSeg

  randomSeed(analogRead(A0)); // Inicializar la semilla del generador de números aleatorios con una lectura analógica
}

void loop() {
  buttonState = digitalRead(buttonPin); // Leer el estado del botón

  if (buttonState == LOW) { // Si se presiona el botón
    randomNumber = random(0, 10); // Generar un número aleatorio entre 0 y 9

    // Mostrar el número en el display de 7 segmentos
    sevseg.setNumber(randomNumber, 1);
    sevseg.refreshDisplay();

    delay(1000); // Mostrar el número durante 1 segundo
    sevseg.blank(); // Apagar el display
  }
}