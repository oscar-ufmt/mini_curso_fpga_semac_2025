#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Motores como saída (PB0 e PB1)
    DDRB = 0b00000011;

    // Sensores como entrada (PD2 e PD3)
    DDRD = 0b00000000;

    while (1) {
        uint8_t sensores = PIND & 0b00001100;

        if (sensores == 0b00000000) {
            // Ambos sensores detectam a linha → em frente
            PORTB = 0b00000011;
        }
        else if (sensores == 0b00000100) {
            // Apenas sensor esquerdo → virar para direita
            PORTB = 0b00000001;
        }
        else if (sensores == 0b00001000) {
            // Apenas sensor direito → virar para esquerda
            PORTB = 0b00000010;
        }
        else {
            // Nenhum sensor detecta → parar
            PORTB = 0b00000000;
        }

        _delay_ms(10);
    }
}

