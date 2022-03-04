#include <avr/io.h>

#define F_CPU 16000000
#define BLINK_DELAY_MS 100

#include <util/delay.h>


const uint8_t BUTTON_PORT12 = DDB4;

const uint8_t RIGHT_BOTTOM_PORT11 = DDB3;
// const uint8_t PORT10 = DDB2;
const uint8_t CENTER_BOTTOM_PORT9 = DDB1;
const uint8_t LEFT_BOTTOM_PORT8 = DDB0;

const uint8_t CENTER_CENTER_PORT2 = DDD2;
const uint8_t LEFT_TOP_PORT3 = DDD3;
const uint8_t CENTER_TOP_PORT4 = DDD4;
const uint8_t RIGHT_TOP_PORT5 = DDD5;

const uint8_t BUTTON_PIN12 = PINB4;

const uint8_t OUTPUT = 1;
const uint8_t INPUT = 0;

const uint8_t ON = 1;
const uint8_t OFF = 0;
void turnOffLed();
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
  pinModeDDRD(CENTER_CENTER_PORT2, OUTPUT);
  pinModeDDRD(LEFT_TOP_PORT3, OUTPUT);
  pinModeDDRD(CENTER_TOP_PORT4, OUTPUT);
  pinModeDDRD(RIGHT_TOP_PORT5, OUTPUT);


  pinModeDDRB(LEFT_BOTTOM_PORT8, OUTPUT);
  pinModeDDRB(CENTER_BOTTOM_PORT9, OUTPUT);
  pinModeDDRB(RIGHT_BOTTOM_PORT11, OUTPUT);
  pinModeDDRB(BUTTON_PORT12, INPUT);

  // int counter = 0;
  while(1) {
    // get value from button on pin 12
    uint8_t buttonOn = digitalReadPINB(BUTTON_PIN12);
    if (buttonOn != 0) {
      digitalWritePIND(CENTER_CENTER_PORT2, OFF);
      digitalWritePIND(LEFT_TOP_PORT3, OFF);
      digitalWritePIND(CENTER_TOP_PORT4, OFF);
      digitalWritePIND(RIGHT_TOP_PORT5, OFF);


      digitalWritePINB(LEFT_BOTTOM_PORT8, OFF);
      digitalWritePINB(CENTER_BOTTOM_PORT9, OFF);
      digitalWritePINB(RIGHT_BOTTOM_PORT11, OFF); 
      // turnOffLed();
      // digitalWritePIND(CENTER_CENTER_PORT2, ON);
      // digitalWritePIND(LEFT_TOP_PORT3, ON);
      // digitalWritePIND(CENTER_TOP_PORT4, ON);
      // digitalWritePIND(RIGHT_TOP_PORT5, ON);


      // digitalWritePINB(LEFT_BOTTOM_PORT8, ON);
      // digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
      // digitalWritePINB(RIGHT_BOTTOM_PORT11, ON);       
      _delay_ms(BLINK_DELAY_MS);
    } else {
      digitalWritePIND(CENTER_CENTER_PORT2, ON);
      digitalWritePIND(LEFT_TOP_PORT3, ON);
      digitalWritePIND(CENTER_TOP_PORT4, ON);
      digitalWritePIND(RIGHT_TOP_PORT5, ON);


      digitalWritePINB(LEFT_BOTTOM_PORT8, ON);
      digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
      digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 


      // digitalWritePIND(CENTER_CENTER_PORT2, OFF);
      // digitalWritePIND(LEFT_TOP_PORT3, OFF);
      // digitalWritePIND(CENTER_TOP_PORT4, OFF);
      // digitalWritePIND(RIGHT_TOP_PORT5, OFF);


      // digitalWritePINB(LEFT_BOTTOM_PORT8, OFF);
      // digitalWritePINB(CENTER_BOTTOM_PORT9, OFF);
      // digitalWritePINB(RIGHT_BOTTOM_PORT11, OFF); 
      _delay_ms(BLINK_DELAY_MS);
    }

    // if (counter == 9) {
    //   counter = 9;
    // } else {
    //   counter++;
    // }
    // turnOffLed();
    // _delay_ms(BLINK_DELAY_MS);


    // handleNumbers(counter);
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


void onZero() {
  digitalWritePIND(LEFT_TOP_PORT3, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);


  digitalWritePINB(LEFT_BOTTOM_PORT8, ON);
  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onOne() {
  digitalWritePIND(RIGHT_TOP_PORT5, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onTwo() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);


  digitalWritePINB(LEFT_BOTTOM_PORT8, ON);
  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
}

void onThree() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);


  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onFour() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(LEFT_TOP_PORT3, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onFive() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(LEFT_TOP_PORT3, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);

  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onSix() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(LEFT_TOP_PORT3, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);

  digitalWritePINB(LEFT_BOTTOM_PORT8, ON);
  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onSeven() {
  digitalWritePIND(CENTER_TOP_PORT4, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onEight() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(LEFT_TOP_PORT3, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);


  digitalWritePINB(LEFT_BOTTOM_PORT8, ON);
  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void onNine() {
  digitalWritePIND(CENTER_CENTER_PORT2, ON);
  digitalWritePIND(LEFT_TOP_PORT3, ON);
  digitalWritePIND(CENTER_TOP_PORT4, ON);
  digitalWritePIND(RIGHT_TOP_PORT5, ON);

  digitalWritePINB(CENTER_BOTTOM_PORT9, ON);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, ON); 
}

void turnOffLed() {
  digitalWritePIND(CENTER_CENTER_PORT2, OFF);
  digitalWritePIND(LEFT_TOP_PORT3, OFF);
  digitalWritePIND(CENTER_TOP_PORT4, OFF);
  digitalWritePIND(RIGHT_TOP_PORT5, OFF);


  digitalWritePINB(LEFT_BOTTOM_PORT8, OFF);
  digitalWritePINB(CENTER_BOTTOM_PORT9, OFF);
  digitalWritePINB(RIGHT_BOTTOM_PORT11, OFF); 
}

void handleNumbers(int counter) {
  // turnOffLed();
  switch (counter)
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