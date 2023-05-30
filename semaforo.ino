const int redPin = 2;     // Pin conectado al LED rojo
const int yellowPin = 3;  // Pin conectado al LED amarillo
const int greenPin = 4;   // Pin conectado al LED verde

const long redDuration = 5000;     // Duración del estado rojo en milisegundos
const long yellowDuration = 2000;  // Duración del estado amarillo en milisegundos
const long greenDuration = 5000;   // Duración del estado verde en milisegundos

void setup() {
  pinMode(redPin, OUTPUT);     // Configurar el pin del LED rojo como salida
  pinMode(yellowPin, OUTPUT);  // Configurar el pin del LED amarillo como salida
  pinMode(greenPin, OUTPUT);   // Configurar el pin del LED verde como salida
}

void loop() {
  // Estado rojo
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(redDuration);

  // Estado rojo y amarillo
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(yellowDuration);

  // Estado verde
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(greenDuration);

  // Estado amarillo
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(yellowDuration);
}