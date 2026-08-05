<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> Traversing from user-code to address

- version - 1 Through the Arduino framework's source files

 ```arduino
 void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
 }
 
 void loop() {
   digitalWrite(LED_BUILTIN, HIGH);
   delay(500);
   digitalWrite(LED_BUILTIN, LOW);
   delay(500);
 }
 ```

<img width="1920" height="1080" alt="sw_abstraction_flow" src="https://github.com/user-attachments/assets/fef23d7d-3572-4117-ab3f-58a27a74e89c" />



- version - 2 Direct register level accessing of the same


> References
1. https://docs.arduino.cc/learn/programming/memory-guide/
2. https://www.geeksforgeeks.org/computer-organization-architecture/difference-between-von-neumann-and-harvard-architecture/
