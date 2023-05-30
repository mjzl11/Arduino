const int triggerPin = 2;  // Pin de disparo del sensor ultrasónico
const int echoPin = 3;     // Pin de eco del sensor ultrasónico
const int ledPin = 13;     // Pin conectado al LED

long duration;             // Duración del pulso recibido desde el sensor ultrasónico
int distance;              // Distancia medida en centímetros

void setup() {
  pinMode(triggerPin, OUTPUT);  // Configurar el pin de disparo como salida
  pinMode(echoPin, INPUT);      // Configurar el pin de eco como entrada
  pinMode(ledPin, OUTPUT);      // Configurar el pin del LED como salida

  Serial.begin(9600);           // Iniciar comunicación serial para imprimir la distancia en el monitor serial
}

void loop() {
  // Generar un pulso de 10 microsegundos para activar el sensor ultrasónico
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Medir la duración del pulso recibido desde el sensor ultrasónico
  duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  distance = duration * 0.034 / 2;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Encender el LED si la distancia es menor o igual a 10 cm, de lo contrario, apagarlo
  if (distance <= 10) {
    digitalWrite(ledPin, HIGH);  // Encender el LED
  } else {
    digitalWrite(ledPin, LOW);   // Apagar el LED
  }

  delay(100);  // Esperar un tiempo antes de realizar la próxima lectura
}