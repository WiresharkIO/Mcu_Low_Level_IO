<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> $\color{blue}{\text{Traversing from user-code to address/memory}}$


- version - 1 Through the Arduino framework's source files

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

<img width="1920" height="1080" alt="sw_abstraction_flow" src="https://github.com/user-attachments/assets/b09769b3-760c-4263-871c-2ebd0209f6d9" />

Until now, the code uses simple human understandable way of performing a function.

(refer: https://arduinogetstarted.com/arduino-language-reference)



The $\color{green}{\text{Clock Speed	is 16 MHz}}$ (16 million clock cycles per second. Each cycle lasts approximately $62.5\\text{ns}$) for this board, which makes one wonder how long will it take to perform a functionality with this sort of sw abstraction?, and how will it compare to alternate implementation with direct register accessing?, and when the application scales up could these difference in latency, memory and other resource parameters, produce the better sw in the optimization space (accepting the fact that the code reduces the readability)?



- version - 2 Direct register level accessing of the same



> $\color{blue}{\text{Basics}}$

The ATmega328P has 3 Timers:
1. Timer0 (8 bit)
2. Timer1 (16 bit)
3. Timer2 (8 bit)

The 16 bit Timer1 provides a good range (0–65535 → max span = 65536 × 62.5 ns = 4.096 ms at prescaler 1), for latency measurement, so we use it to measure the time. 






