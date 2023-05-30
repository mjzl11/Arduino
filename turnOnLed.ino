const int switchPin = 2; // Pin conectado al interruptor
const int ledPin = 13; // Pin conectado al LED

int switchState = 0; // Variable para almacenar el estado del interruptor

void setup() {
  pinMode(ledPin, OUTPUT); // Configurar el pin del LED como salida
  pinMode(switchPin, INPUT); // Configurar el pin del interruptor como entrada
}

void loop() {
  switchState = digitalRead(switchPin); // Leer el estado del interruptor

  if (switchState == HIGH) {
    digitalWrite(ledPin, HIGH); // Encender el LED si el interruptor está activado
  } else {
    digitalWrite(ledPin, LOW); // Apagar el LED si el interruptor está desactivado
  }
}