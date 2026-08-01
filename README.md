<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> Introduction

To make anything work, we as humans need to access some information related to that particular work. We do that so, by either recalling our prior knowledge or if the work is novel we need to build-up the knowledge, but in any case, all the information whether relevant or irrelevant ends up in our memory.


Similarly if you think of any embedded system, the core, all the logic boils down to some bit flips which is stored in a particular space (a memory), identified by an address for ease of accessing (unlike humans).


<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />

> Memory-mapped I/O (MMIO)

**Memory-mapped I/O** assigns hardware peripheral registers to specific physical addresses in the standard memory space. The CPU uses regular load and store instructions to read or write to these addresses just like normal RAM.

so these load/store/read/write all are contributing to perform some function, it could be anything, I'll just leave it out for your imagination.

In this primer, we see how memory mapped IO can be controlled by using **_direct register access_** and through **_software abstraction_** library, in both case the code deals with a particular address and a value present at that address to control something, here control could mean controlling the pitch of an aircraft fan blades to controlling a simple LED.


<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />

> Arduino IO interaction

This repo uses application which makes every embedded systems engineer feel good about themselves.. "Blink LED at a particular rate"


We employ Arduino Uno, for the first application as it is the most simplest board known for prototyping and experimenting.
In Arduino Uno Board -> **we have ATmega328P microcontroller** --> with an 8-bit AVR microprocessor.

[If we have to mentally map it to other boards we can take an example of STM32 where we have,
STM32 nano or discovery boards -> with say STM32wb5mmg controller --> with an ARM cortex M4F processor..]


<img width="1920" height="1080" alt="Untitled presentation (4)" src="https://github.com/user-attachments/assets/b33ec8e3-aee9-4847-859a-dc6313168f4c" />

On an AVR like the ATmega328P, what’s happening is:
- It follows a _Pure Harvard Architecture_, meaning a completely separate memory spaces, wires, and addresses for code and data (a naive way is to look for the start addresses of each of the memory spaces, it all starts from 0x000...0 but in Pure _Von Neumann Architecture_, one unified memory space for everything with distinct addresses so 0x000...0 will be present only once in that entire memory space).
- There is one unified _**data address space**_ the CPU uses for load/store instructions.


<img width="1474" height="1043" alt="Untitled presentation (6)" src="https://github.com/user-attachments/assets/bf4bb3de-0f32-4b66-bf48-196e4523e2fb" />


 

Inside that address space, different ranges are wired to different things:

- A chunk is SRAM (normal variables, stack, etc.).
- A chunk is I/O registers (DDRB, PORTB, PINB, etc.).
- General Purpose Registers (which the CPU uses to load and store data for immediate math operations).

The CPU doesn’t “know” which is which; it just sees an address and executes a normal read/write. The chip’s internal bus logic decides whether that address hits RAM or a peripheral register.

To find the exact pin-to-register or port mapping, the ATmega microcontroller datasheet or an Arduino pinout diagram should be referred.

> Why

This primer will also enhance comfortability in referring datasheets, accessing addresses, defining pointer, and doing bitwise operations for bit manipulation in a register.


> References
