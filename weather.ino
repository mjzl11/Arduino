const int analogPin = A0;    // Pin analógico conectado al sensor LM35
const int blueLedPin = 2;   // Pin conectado al LED azul
const int greenLedPin = 3;  // Pin conectado al LED verde
const int redLedPin = 4;    // Pin conectado al LED rojo

float temperature;           // Variable para almacenar la temperatura medida

void setup() {
  pinMode(blueLedPin, OUTPUT);   // Configurar el pin del LED azul como salida
  pinMode(greenLedPin, OUTPUT);  // Configurar el pin del LED verde como salida
  pinMode(redLedPin, OUTPUT);    // Configurar el pin del LED rojo como salida

  Serial.begin(9600);   // Iniciar comunicación serial para imprimir la temperatura en el monitor serial
}

void loop() {
  // Leer el valor analógico del sensor LM35 y convertirlo a temperatura en grados Celsius
  int sensorValue = analogRead(analogPin);
  temperature = (sensorValue * 5.0 / 1023.0) * 100.0;

  // Imprimir la temperatura en el monitor serial
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Encender o apagar los LEDs según el rango de temperatura
  if (temperature < 10) {
    digitalWrite(blueLedPin, HIGH);    // Encender el LED azul
    digitalWrite(greenLedPin, LOW);    // Apagar el LED verde
    digitalWrite(redLedPin, LOW);      // Apagar el LED rojo
  } else if (temperature >= 10 && temperature < 30) {
    digitalWrite(blueLedPin, LOW);     // Apagar el LED azul
    digitalWrite(greenLedPin, HIGH);   // Encender el LED verde
    digitalWrite(redLedPin, LOW);      // Apagar el LED rojo
  } else {
    digitalWrite(blueLedPin, LOW);     // Apagar el LED azul
    digitalWrite(greenLedPin, LOW);    // Apagar el LED verde
    digitalWrite(redLedPin, HIGH);     // Encender el LED rojo
  }

  delay(1000);  // Esperar un segundo antes de realizar la próxima lectura
}