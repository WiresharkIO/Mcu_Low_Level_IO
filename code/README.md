<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> Traversing from user-code to address/memory

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

The $\color{blue}{\text{Clock Speed	is 16 MHz}}$ for this board, which makes one wonder how long will it take to perform a functionality with this sort of sw abstraction?, and how will it compare to alternate implementations?, and when the application scales up could these difference in latency, memory and other resource parameters, between different approaches matter?

- version - 2 Direct register level accessing of the same


> References
1. https://docs.arduino.cc/learn/programming/memory-guide/
2. https://www.geeksforgeeks.org/computer-organization-architecture/difference-between-von-neumann-and-harvard-architecture/


