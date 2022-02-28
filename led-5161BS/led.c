#include <avr/io.h>

#define F_CPU 16000000
#define BLINK_DELAY_MS 100

#include <util/delay.h>


const uint8_t PORT12 = DDB4;

const uint8_t PORT11 = DDB3;
const uint8_t PORT10 = DDB2;
const uint8_t PORT9 = DDB1;
const uint8_t PORT8 = DDB0;

// const uint8_t PORT3 = DDA2;
const uint8_t PORTT2 = DDD2;

const uint8_t PIN12 = PINB4;

const uint8_t OUTPUT = 1;
const uint8_t INPUT = 0;

const uint8_t ON = 1;
const uint8_t OFF = 0;

void pinModeDDRD(uint8_t port, uint8_t mode);
void digitalWritePIND(uint8_t port, uint8_t value);
uint8_t digitalReadPIND(uint8_t pin);

void pinModeDDRB(uint8_t port, uint8_t mode);
void digitalWritePINB(uint8_t port, uint8_t value);
uint8_t digitalReadPINB(uint8_t pin);

int main() {
  pinModeDDRD(PORTT2, OUTPUT);

  pinModeDDRB(PORT8, OUTPUT);
  pinModeDDRB(PORT9, OUTPUT);
  pinModeDDRB(PORT10, OUTPUT);
  pinModeDDRB(PORT11, OUTPUT);
  pinModeDDRB(PORT12, INPUT);

  while(1) {
    // get value from button on pin 12
    uint8_t buttonOn = digitalReadPINB(PIN12);

    if (buttonOn != 0) {
      digitalWritePIND(PORTT2, OFF);

      digitalWritePINB(PORT8, OFF);
      digitalWritePINB(PORT9, OFF);
      digitalWritePINB(PORT10, OFF);
      digitalWritePINB(PORT11, OFF);
      _delay_ms(BLINK_DELAY_MS);
    } else { 
      digitalWritePIND(PORTT2, ON);

      digitalWritePINB(PORT8, ON);
      digitalWritePINB(PORT9, ON);
      digitalWritePINB(PORT10, ON);
      digitalWritePINB(PORT11, ON); 
      _delay_ms(BLINK_DELAY_MS);
    }
  }
}

// WORKS ONLY WITH DDRB PORTS (8 - 13)!!!
void pinModeDDRB(uint8_t port, uint8_t mode) {
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
uint8_t digitalReadPINB(uint8_t pin) {
  if ((PINB & (1 << pin)) != 0) {
    return 1;
  }

  return 0;
}

// WORKS ONLY WITH DDRB PORTS (8 - 13)!!!
void digitalWritePINB(uint8_t port, uint8_t value) {
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

// WORKS ONLY WITH DDRA PORTS (0 - 7)!!!
void pinModeDDRD(uint8_t port, uint8_t mode) {
  switch (mode)
  {
  case OUTPUT:
    DDRD |=  (1 << port);
    break;

  case INPUT:
    DDRD &= ~(1 << port);    
    break;

  default:
    break;
  }
}

// WORKS ONLY WITH 'A' PINS (0 - 7)!!!
uint8_t digitalReadPIND(uint8_t pin) {
  if ((PIND & (1 << pin)) != 0) {
    return 1;
  }

  return 0;
}

// WORKS ONLY WITH DDRB PORTS (0 - 7)!!!
void digitalWritePIND(uint8_t port, uint8_t value) {
  switch (value)
  {
  case ON:
    PORTD |= (1 << port);
    break;

  case OFF:
    PORTD &= ~(1 << port);
  break;

  default:
    break;
  }
}


