/*Run one version at a time.*/

/* 
version-1
Latency analysis with SW abstracted access to IO !!
*/

// pinMode cycles: 42 | Latency: 2.6250 us
// digitalWrite Cycles: 54 | Latency: 3.3750 us

void setup() {
  Serial.begin(115200);
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS10);

  unsigned int startTime, endTime, cycleCount;
  float microseconds;

  startTime = TCNT1;
  pinMode(LED_BUILTIN, OUTPUT);
  endTime = TCNT1;

  cycleCount = endTime - startTime;
  if (cycleCount > 0) cycleCount -= 3;
  microseconds = cycleCount * 0.0625;

  Serial.print("pinMode cycles: ");
  Serial.print(cycleCount);
  Serial.print(" | Latency: ");
  Serial.print(microseconds, 4);
  Serial.println(" us");
}

void loop() {

  unsigned int startTime;
  unsigned int endTime;
  unsigned int cycleCount;
  float microseconds;

  startTime = TCNT1;

  digitalWrite(LED_BUILTIN, HIGH);

  endTime = TCNT1;

  cycleCount = endTime - startTime;

  if (cycleCount > 0) cycleCount -= 3; 

  microseconds = cycleCount * 0.0625;

  Serial.print("digitalWrite Cycles: ");
  Serial.print(cycleCount);
  Serial.print(" | Latency: ");
  Serial.print(microseconds, 4);
  Serial.println(" us");
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}


/* 
version-2
Latency analysis with direct register access to IO (MMIO) !! 
*/

// DDRB_ADDR cycles: 3 | Latency: 0.1875 us
// PORTB_ADDR Cycles: 3 | Latency: 0.1875 us

#define DDRB_ADDR   ((volatile uint8_t *)0x24)
#define PORTB_ADDR  ((volatile uint8_t *)0x25)

void setup() {
  Serial.begin(115200);

  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS10);

  unsigned int startTime, endTime, cycleCount;
  float microseconds;

  startTime = TCNT1;
  *DDRB_ADDR |= (1 << PORTB5);
  endTime = TCNT1;

  cycleCount = endTime - startTime;
  if (cycleCount > 0) cycleCount -= 3;
  microseconds = cycleCount * 0.0625;

  Serial.print("DDRB cycles: ");
  Serial.print(cycleCount);
  Serial.print(" | Latency: ");
  Serial.print(microseconds, 4);
  Serial.println(" us");
}

void loop() {
  unsigned int startTime;
  unsigned int endTime;
  unsigned int cycleCount;
  float microseconds;

  startTime = TCNT1;

  *PORTB_ADDR |= (1 << PORTB5);

  endTime = TCNT1;

  cycleCount = endTime - startTime;

  if (cycleCount > 0) cycleCount -= 3; 

  microseconds = cycleCount * 0.0625;

  Serial.print("PORTB_ADDR Cycles: ");
  Serial.print(cycleCount);
  Serial.print(" | Latency: ");
  Serial.print(microseconds, 4);
  Serial.println(" us");
  delay(500);
  *PORTB_ADDR &= ~(1 << PORTB5);
  delay(500);
}
