#include <avr/io.h>

#define F_CPU 16000000
#define BLINK_DELAY_MS 100

#include <util/delay.h>


const uint8_t PORT13 = DDB5;
const uint8_t PORT12 = DDB4;

const uint8_t PIN12 = PINB4;

const uint8_t OUTPUT = 1;
const uint8_t INPUT = 0;

const uint8_t ON = 1;
const uint8_t OFF = 0;

void pinMode(uint8_t port, uint8_t mode);
void analogWrite(uint8_t port, uint8_t value);
uint8_t analogRead(uint8_t pin);

int main() {
  pinMode(PORT13, OUTPUT);
  pinMode(PORT12, INPUT);

  while(1) {
    // get value from button on pin 12
    uint8_t buttonOn = analogRead(PIN12);

    if (buttonOn != 0) {
      // turn LED on
      analogWrite(PORT13, ON);
      _delay_ms(BLINK_DELAY_MS);
    } else { 
      // turn LED off
      analogWrite(PORT13, OFF);
      _delay_ms(BLINK_DELAY_MS);
    }
  }
}

// WORKS ONLY WITH DDRB PORTS (8 - 13)!!!
void pinMode(uint8_t port, uint8_t mode) {
  switch (mode)
  {
  case OUTPUT:
    DDRB |=  (1 << port);
    break;

  case INPUT:
    DDRB &= ~(1 << port);    
    break;

  default:
    break;
  }
}

// WORKS ONLY WITH 'B' PINS (8 - 13)!!!
uint8_t analogRead(uint8_t pin) {
  if ((PINB & (1 << pin)) != 0) {
    return 1;
  }

  return 0;
}

// WORKS ONLY WITH DDRB PORTS (8 - 13)!!!
void analogWrite(uint8_t port, uint8_t value) {
  switch (value)
  {
  case ON:
    PORTB |= (1 << port);
    break;

  case OFF:
    PORTB &= ~(1 << port);
  break;

  default:
    break;
  }
}

