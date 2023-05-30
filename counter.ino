#include <SevSeg.h>

const int echoPin = 2;        // Pin conectado al pin ECHO del sensor de sonar
const int triggerPin = 3;     // Pin conectado al pin TRIGGER del sensor de sonar
const int displayPin1 = 4;    // Pin conectado al segmento A del display
const int displayPin2 = 5;    // Pin conectado al segmento B del display
const int displayPin3 = 6;    // Pin conectado al segmento C del display
const int displayPin4 = 7;    // Pin conectado al segmento D del display
const int displayPin5 = 8;    // Pin conectado al segmento E del display
const int displayPin6 = 9;    // Pin conectado al segmento F del display
const int displayPin7 = 10;   // Pin conectado al segmento G del display

SevSeg sevseg;                // Objeto de la biblioteca SevSeg

int distance = 0;             // Variable para almacenar la distancia medida por el sensor de sonar
int number = 0;               // Variable para almacenar el número a mostrar en el display

void setup() {
  pinMode(echoPin, INPUT);    // Configurar el pin del sensor de sonar como entrada
  pinMode(triggerPin, OUTPUT);// Configurar el pin del sensor de sonar como salida
  digitalWrite(triggerPin, LOW); // Establecer el pin del sensor de sonar en estado bajo

  // Configurar los pines del display como salida
  pinMode(displayPin1, OUTPUT);
  pinMode(displayPin2, OUTPUT);
  pinMode(displayPin3, OUTPUT);
  pinMode(displayPin4, OUTPUT);
  pinMode(displayPin5, OUTPUT);
  pinMode(displayPin6, OUTPUT);
  pinMode(displayPin7, OUTPUT);

  byte numDigits = 2;       // Número de dígitos en el display (en este caso, se muestra el número en 2 dígitos)
  byte digitPins[] = {displayPin1, displayPin2, displayPin3, displayPin4, displayPin5, displayPin6, displayPin7}; // Pines de los segmentos del display
  byte segmentPins[] = {displayPin7, displayPin6, displayPin5, displayPin4, displayPin3, displayPin2, displayPin1}; // Pines de los dígitos del display
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins); // Inicializar el objeto SevSeg

  Serial.begin(9600);   // Iniciar comunicación serial para imprimir la distancia medida en el monitor serial
}

void loop() {
  // Generar un pulso de 10 microsegundos en el pin TRIGGER para iniciar una medición
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Leer la duración del pulso de eco (en microsegundos) y calcular la distancia en centímetros
  unsigned long duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Incrementar el número si la distancia medida es menor o igual a 50 cm
  if (distance <= 50) {
    number++;
    if (number > 99) {
      number = 0;
    }
  }

  // Mostrar el número en el display de 7 segmentos
  sevseg.setNumber(number, 2); // Mostrar el número en 2 dígitos
  sevseg.refreshDisplay();

  // Imprimir la distancia medida en el monitor serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  delay(1000);  // Esperar un segundo antes de realizar la próxima medición
}