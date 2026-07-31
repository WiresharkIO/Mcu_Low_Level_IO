> Introduction

**Memory-mapped I/O (MMIO)** assigns hardware peripheral registers to specific physical addresses in the standard memory space. The CPU uses regular load and store instructions to read or write to these addresses just like normal RAM.

In this primer, we see how memory mapped IO can be controlled by using **_direct register access_** and through **_software abstraction_** library, in both case the code deals with a particular address and a value present at that address to control something, here control could mean controlling the pitch of an aircraft fan blades to controlling a simple LED.


This repo uses application which makes every embedded systems engineer feel good about themselves.. "Blink LED at a particular rate"

In Arduino Uno Board -> **we have ATmega328P microcontroller** --> with an 8-bit AVR microprocessor.

If we have to mental map it to other boards we can take an example of STM32 where we have,

STM32 nano or discovery boards -> with say STM32wb5mmg controller --> with an ARM cortex M4F processor..


<img width="1920" height="1080" alt="Untitled presentation (4)" src="https://github.com/user-attachments/assets/b33ec8e3-aee9-4847-859a-dc6313168f4c" />

To find the exact pin-to-register or port mapping, the ATmega microcontroller datasheet or an Arduino pinout diagram should be referred.

> Why

This primer will also enhance comfortability in referring datasheets, accessing addresses, defining pointer, and doing bitwise operations for bit manipulation in a register.


> References
