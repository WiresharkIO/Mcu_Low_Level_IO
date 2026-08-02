/*
Code with software abstraction based implementation. But underneath, the 
most basic thing which the code transcends to is an address, and the register 
configuration at that address..
*/

/*Flash consumption which is the compiled program code - 924 bytes..*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

/*
Flash consumption which is the compiled program code - 640 bytes..
*/

void setup() {
  DDRB |= (1 << DDB5);
}

void loop() {
  PORTB |= (1 << PORTB5);
  delay(500);
  PORTB &= ~(1 << PORTB5);
  delay(500);
}



#define DDRB_ADDR   ((volatile uint8_t *)0x24)
#define PORTB_ADDR  ((volatile uint8_t *)0x25)

void setup() {
  *DDRB_ADDR |= (1 << PORTB5);
}

void loop() {
  *PORTB_ADDR |= (1 << PORTB5);
  delay(500);
  *PORTB_ADDR &= ~(1 << PORTB5);
  delay(500);
}
