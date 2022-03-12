#include <avr/io.h>

#define F_CPU 16000000
#define BLINK_DELAY_MS 1000

#include <util/delay.h>


const uint8_t BUTTON_PORT12 = DDB4;

const uint8_t PORT_B10 = DDB2;
const uint8_t PORT_B9 = DDB1;
const uint8_t PORT_B8 = DDB0;

const uint8_t PORT_D2 = DDD2;
const uint8_t PORT_D3 = DDD3;
const uint8_t PORT_D4 = DDD4;
const uint8_t PORT_D5 = DDD5;

const uint8_t BOTTOM_LEFT  = 0b11111110;
const uint8_t BOTTOM_CENTER = 0b11111101;
const uint8_t BOTTOM_RIGHT   = 0b11111011;

const uint8_t TOP_LEFT   =  0b11111011;
const uint8_t TOP_CENTER =  0b11110111;
const uint8_t TOP_RIGHT  =  0b11101111;


const uint8_t BUTTON_PIN12 = PINB4;

const uint8_t OUTPUT = 1;
const uint8_t INPUT = 0;

const uint8_t ON = 1;
const uint8_t OFF = 0;
void turnOffLED();
void turnOffPINB();
void turnOffPIND();
void handleNumbers(int counter);
void onZero();
void onOne();
void onTwo();
void onThree();
void onFour();
void onFive();
void onSix();
void onSeven();
void onEight();
void onNine();

void pinModeDDRD(uint8_t port, uint8_t mode);
void digitalWritePIND(uint8_t port, uint8_t value);
uint8_t digitalReadPIND(uint8_t pin);

void pinModeDDRB(uint8_t port, uint8_t mode);
void digitalWritePINB(uint8_t port, uint8_t value);
uint8_t digitalReadPINB(uint8_t pin);

int main() {
  pinModeDDRD(PORT_D2, OUTPUT);
  pinModeDDRD(PORT_D3, OUTPUT);
  pinModeDDRD(PORT_D4, OUTPUT);


  pinModeDDRB(PORT_B8, OUTPUT);
  pinModeDDRB(PORT_B9, OUTPUT);
  pinModeDDRB(PORT_B10, OUTPUT);
  // pinModeDDRB(BUTTON_PORT12, INPUT);

  turnOffLED();
  while(1) {
    for(int i = 0; i <= 9; i++) {
      handleNumbers(i);
      _delay_ms(BLINK_DELAY_MS / 2);

      turnOffLED();
        _delay_ms(BLINK_DELAY_MS / 2);
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
    PORTB = ~(~PORTB | ~port);
    break;

  case OFF:
    PORTB = ~(PORTB ^ port);
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
    PORTD = ~(~PORTD | ~port);
    break;

  case OFF:
    PORTD = ~(PORTD ^ port);
  break;

  default:
    break;
  }
}


void onZero() {
  digitalWritePIND(TOP_LEFT, ON);
  digitalWritePIND(TOP_CENTER, ON);
  
  digitalWritePIND(TOP_RIGHT, ON);
  digitalWritePINB(BOTTOM_LEFT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON);
  digitalWritePINB(BOTTOM_RIGHT, ON);
}

void onOne() {
  digitalWritePIND(TOP_RIGHT, ON);

  digitalWritePINB(BOTTOM_RIGHT, ON); 
}

void onTwo() {
  digitalWritePIND(TOP_CENTER, ON);
  digitalWritePIND(TOP_RIGHT, ON);
  // digitalWritePIND(CENTER_CENTER, ON);


  digitalWritePINB(BOTTOM_LEFT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON);
}

void onThree() {
 digitalWritePIND(TOP_CENTER, ON);
  digitalWritePIND(TOP_RIGHT, ON);
  // digitalWritePIND(CENTER_CENTER, ON);


  digitalWritePINB(BOTTOM_RIGHT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON);
}

void onFour() {
  digitalWritePIND(TOP_LEFT, ON);
  digitalWritePIND(TOP_RIGHT, ON);
  // digitalWritePIND(CENTER_CENTER, ON);
  digitalWritePINB(BOTTOM_RIGHT, ON); 
}

void onFive() {
  digitalWritePIND(TOP_LEFT, ON);
  digitalWritePIND(TOP_CENTER, ON);
  // digitalWritePIND(CENTER_CENTER, ON);

  digitalWritePINB(BOTTOM_RIGHT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON); 
}

void onSix() {
  digitalWritePIND(TOP_LEFT, ON);
  digitalWritePIND(TOP_CENTER, ON);
  // digitalWritePIND(CENTER_CENTER, ON);

  digitalWritePINB(BOTTOM_LEFT, ON);
  digitalWritePINB(BOTTOM_RIGHT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON); 
}

void onSeven() {
  digitalWritePIND(TOP_RIGHT, ON);
  digitalWritePIND(TOP_CENTER, ON);
  digitalWritePINB(BOTTOM_RIGHT, ON); 
}

void onEight() {
  digitalWritePIND(TOP_CENTER, ON);
  digitalWritePIND(TOP_LEFT, ON);
  digitalWritePIND(TOP_RIGHT, ON);
  // digitalWritePIND(CENTER_CENTER, ON);


  digitalWritePINB(BOTTOM_LEFT, ON);
  digitalWritePINB(BOTTOM_RIGHT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON); 
}

void onNine() {
  digitalWritePIND(TOP_LEFT, ON);
  digitalWritePIND(TOP_RIGHT, ON);
  digitalWritePIND(TOP_CENTER, ON);
  // digitalWritePIND(CENTER_CENTER, ON);

  digitalWritePINB(BOTTOM_RIGHT, ON);
  digitalWritePINB(BOTTOM_CENTER, ON); 
}

void turnOffLED() {
  PORTD = ~0;
  PORTB = ~0;
}
void turnOffPIND() {
  PORTD = ~0;
}

void turnOffPINB() {
  PORTB = ~0;
}

void handleNumbers(int number) {
  switch (number)
  {
  case 0:
    onZero();
    break;
  case 1:
    onOne();
    break;
  case 2:
    onTwo();
    break;
  case 3:
    onThree();
    break;
  case 4:
    onFour();
    break;
  case 5:
    onFive();
    break;
  case 6:
    onSix();
    break;
  case 7:
    onSeven();
    break;
  case 8:
    onEight();
    break;
  case 9:
    onNine();
    break;
  
  default:
    break;
  }
}