<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> $\color{blue}{\text{Introduction}}$

To make anything work, we as humans need to access some information related to that particular work. We do that so, by either recalling our prior knowledge or if the work is novel we need to build-up the knowledge, but in any case, all the information whether relevant or irrelevant ends up in our memory.


Similarly if you think of any embedded system, the core, all the logic boils down to some bit flips which is stored in a particular space (a memory), identified by an address for ease of accessing (unlike humans).


<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />

>  $\color{blue}{\text{Memory-mapped I/O (MMIO)}}$ 

**Memory-mapped I/O** assigns hardware peripheral registers to specific physical addresses in the standard memory space. The CPU uses regular load and store instructions to read or write to these addresses just like normal RAM.

so these load/store/read/write all are contributing to perform some function, it could be anything, I'll just leave it out for your imagination.

In this primer, we see how memory mapped IO can be controlled by using **_direct register access_** and through **_software abstraction_** library, in both case the code deals with a particular address and a value present at that address to control something, here control could mean controlling the pitch of an aircraft fan blades to controlling a simple LED.


<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />


> $\color{blue}{\text{Why this analysis what's the point?}}$

- This primer will also enhance comfortability in referring datasheets, accessing addresses, defining pointer, and doing bitwise operations for bit manipulation in a register.

- For resource constrained devices and applications that consumes significant flash, register level bit manipulation could cut corners in terms of flash utilization.
  
- This will tell that on bare metal how does any software perform, that is with just the interaction with the core nature of the hardware how does any functionality perform in terms of resource consumption.

<img width="1000" height="50" alt="github_asthetics_copy" src="https://github.com/user-attachments/assets/a6184963-c508-4fad-959d-255393f54737" />

> $\color{blue}{\text{References:}}$
1. https://docs.arduino.cc/learn/programming/memory-guide/
2. https://www.geeksforgeeks.org/computer-organization-architecture/difference-between-von-neumann-and-harvard-architecture/


> $\color{Red}{\text{TO DO:}}$
1. Calculate latencies (document flash usage)
2. Adapting register level access in STM32 or ESP32 type boards
3. Adapting this to a medium sized application with reduced invocations to abstractions
4. compare latencies, flash (if possible power) across Arduino, STM32 (or ESP32) based platforms
5. reasoning and observations for optimization based the analysis

> $\color{blue}{\text{Basics}}$

$\color{yellow}{\text{Device/Memory Accessing}}$

There are many instructions that read/write memory or device registers:
- For example, x86: MOV, PUSH, POP, XCHG, CMP, arithmetic/logical ops with memory operands, etc.
For example, ARM/RISC‑V: LD, ST, LDR, STR, etc.
- All of these use addresses and addressing modes to access memory/ MMIO, but the problem is that it cannot differentiate between different types of memory for example RAM or GPU or NIC..
- Assume all these devices have a particular address 0x1000200 now how will the processor differentiate which memory to interact with?


It is basically solved in the system designing phase:

1. The system designer assigns non‑overlapping address ranges for RAM and each MMIO device.

2. Uses an address decoder and chip‑select signals, so that for a given address, exactly one device responds on the bus.

3. In systems that also use port‑mapped I/O, some devices live in a separate I/O port space and are accessed with special I/O instructions (IN, OUT) instead of memory instructions.


**$\color{yellow}{\text{Bit-wise operations}}$**

<!--
This repo uses application which makes every embedded systems engineer feel good about themselves..

"Blink LED at a particular rate" as the first use-case.. - as the application is simple it makes the understanding clearer as to why one would configure registers directly over sw abstraction flow.

Then we will be looking into some embedded ai based applications, where we keep the model params constant but try to make the supporting firmware a bit more optimized by this approach (we don't know that yet for sure whether it will produce any effect or not, we need to evaluate it)..

-->
