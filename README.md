In this primer, we see how memory mapped IO can be controlled by using direct register access and through software abstraction library, in both case the thing which any code deals with is a particular address and the value present in that address to control something, here control could mean controlling the pitch of an aircraft fan blades to controlling a simple LED,. 

This is just for increasing comfortability in referring datasheets, accessing addresses, defining pointer, and doing bitwise operations for bit manipulation in a register.

This repo uses application which makes every embedded systems engineer feel good about themselves.. "Blink LED at a particular rate"

In Arduino Uno Board -> **we have ATmega328P microcontroller** --> with an 8-bit AVR microprocessor

To find the exact pin-to-register or port mapping, you should look for the ATmega microcontroller datasheet or an Arduino pinout diagram

<img width="1920" height="1080" alt="Untitled presentation (4)" src="https://github.com/user-attachments/assets/b33ec8e3-aee9-4847-859a-dc6313168f4c" />
