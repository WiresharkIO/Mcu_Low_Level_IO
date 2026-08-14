<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> $\color{blue}{\text{Traversing from user-code to address/memory}}$

<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />

$\color{blue}{\text{version - 1 Through the Arduino framework's source files}}$

 ```arduino
 void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
 }
 
 void loop() {
   digitalWrite(LED_BUILTIN, HIGH);
   delay(500); <--- just to see the blink properly,.
   digitalWrite(LED_BUILTIN, LOW);
   delay(500);
 }
 ```

<!-- 
<img width="1920" height="1080" alt="sw_abstraction_flow" src="https://github.com/user-attachments/assets/b09769b3-760c-4263-871c-2ebd0209f6d9" /> 
-->
<img width="1920" height="1080" alt="sw_abstraction_flow" src="https://github.com/user-attachments/assets/13be01f1-42a2-4940-aba0-5c6b65ceea76" />

Until now, the code uses simple human understandable way of performing a function.

(refer: https://arduinogetstarted.com/arduino-language-reference)



The $\color{green}{\text{Clock Speed	is 16 MHz}}$ (16 million clock cycles per second. Each cycle lasts approximately $62.5\\text{ns}$) for this board, which makes one wonder how long will it take to perform a functionality with this sort of sw abstraction?, and how will it compare to alternate implementation with direct register accessing?, and when the application scales up could these difference in latency, memory and other resource parameters, produce the better sw in the optimization space (accepting the fact that the code reduces the readability)?


<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


$\color{blue}{\text{version - 2 Direct register level IO accessing}}$

It is almost always important to refer datasheet when configuring or writing onto memory, and not take the address or register information from somewhere else on the internet.


Why?

If the associated embedded application is not critical and doesn't lead to any catastrophe it's still fine to brainstorm with internet based values, but assume an application such as a FADEC system (watch: https://www.youtube.com/watch?v=f9jAtjBRkpE), which translates to full authority digital engine control in an aircraft, which allows no form of manual override nor manual controls, placing full authority over all of the operating parameters of the engine in the hands of the computer. In these cases one cannot brainstorm, and the answer must be deterministic and deterministic answers are available in the datasheets and reference manuals.


<p align="center">
  <img width="320" height="240" alt="image" src="https://github.com/user-attachments/assets/e97532f1-12ae-4c71-8188-6a241053d79b">
  <br>
  <em>Figure 1: A FADEC system (https://en.wikipedia.org/wiki/FADEC).
</p>

For this arduino uno board which has Atmega328p as a microcontroller - refer: https://www.microchip.com/en-us/product/atmega328p#Overview.

 ```arduino
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
```

> $\color{blue}{\text{Latency comparison}}$
<img width="3579" height="1769" alt="arduino_io_latency" src="https://github.com/user-attachments/assets/ab2cdf1c-f15f-42d8-9166-7aad3f875d84" />



> $\color{blue}{\text{Basics}}$

The ATmega328P has 3 Timers:
1. Timer0 (8 bit)
2. Timer1 (16 bit)
3. Timer2 (8 bit)

The 16 bit Timer1 provides a good range (0–65535 → max span = 65536 × 62.5 ns = 4.096 ms at prescaler 1), for latency measurement, so we use it to measure the time.

Its better to tune prescaler value based on the application in hand, as if not done so the counter wraps after reaching its max value (overflow).






