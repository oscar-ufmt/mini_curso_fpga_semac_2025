// Pinos dos sensores
const int sensorEsq = 2;
const int sensorDir = 3;

// Pinos motores
const int motorEsqFrente = 5;
const int motorEsqParar = 6; // desligar motor esquerdo
const int motorDirFrente = 9;
const int motorDirParar = 10; // desligar motor direito

void setup() {
  pinMode(sensorEsq, INPUT);
  pinMode(sensorDir, INPUT);

  pinMode(motorEsqFrente, OUTPUT);
  pinMode(motorEsqParar, OUTPUT);
  pinMode(motorDirFrente, OUTPUT);
  pinMode(motorDirParar, OUTPUT);
}

void loop() {
  int esq = digitalRead(sensorEsq);
  int dir = digitalRead(sensorDir);

  if (esq == LOW && dir == LOW) {
    // Seguir em frente
    digitalWrite(motorEsqFrente, HIGH);
    digitalWrite(motorEsqParar, LOW);

    digitalWrite(motorDirFrente, HIGH);
    digitalWrite(motorDirParar, LOW);
  } 
  else if (esq == LOW && dir == HIGH) {
    // Virar à esquerda
    digitalWrite(motorEsqFrente, LOW);
    digitalWrite(motorEsqParar, HIGH);

    digitalWrite(motorDirFrente, HIGH);
    digitalWrite(motorDirParar, LOW);
  }
  else if (esq == HIGH && dir == LOW) {
    // Virar à direita
    digitalWrite(motorEsqFrente, HIGH);
    digitalWrite(motorEsqParar, LOW);

    digitalWrite(motorDirFrente, LOW);
    digitalWrite(motorDirParar, HIGH);
  }
  else {
    // Parar
    digitalWrite(motorEsqFrente, LOW);
    digitalWrite(motorEsqParar, HIGH);

    digitalWrite(motorDirFrente, LOW);
    digitalWrite(motorDirParar, HIGH);
  }
}

