# ATmega16 Stop-Watch System with Multiplexed 7-Segment Display

## Project Specifications

1. **Microcontroller:** ATmega16
2. **Microcontroller Frequency:** 1MHz
3. **Timer Configuration:** Timer1 with CTC Mode
4. **Display:** Six Common Anode 7-Segment Displays
5. **Multiplexing:** Utilizing 7447 Decoder and NPN BJT Transistors
6. **Control Pins:** First 4 pins of PORTC for 7447 Decoder, First 6 pins of PORTA for Enable/Disable
7. **Startup:** Stop Watch counting starts upon connecting power to the MCU
8. **External Interrupt INT0:** Falling edge detection to reset the Stop Watch time
9. **External Interrupt INT1:** Rising edge detection to pause the Stop Watch time
10. **External Interrupt INT2:** Falling edge detection to resume the Stop Watch time


## Code Overview

The main code file for this project can be found [here](https://github.com/Salahbendary/Stop-Watch-System/blob/main/MiniProject2SalahKhaled/MiniProject2SalahKhaled/MiniProject2SalahKhaled.c). This C code is responsible for configuring the ATmega16 microcontroller, setting up Timer1 in CTC mode, configuring external interrupts, and implementing the stop-watch logic.


## Usage

Follow these steps to use the stop-watch system:
1. Upload the provided code to the ATmega16 microcontroller using a suitable programmer.
2. Set up the hardware components as per the instructions in the hardware setup guide.
3. Power on the circuit to start the stop-watch counting automatically.
4. Use the push-buttons connected to INT0, INT1, and INT2 to control the stop-watch:
   - Pressing the INT0 button (falling edge) will reset the stop-watch time.
   - Pressing the INT1 button (rising edge) will pause the stop-watch time.
   - Pressing the INT2 button (falling edge) will resume the stop-watch time.

## Additional Resources

- [Project PDF Requirements](https://github.com/Salahbendary/Stop-Watch-System/blob/main/MiniProject2SalahKhaled/Mini%20Project%202.pdf)
- [Simulation in Proteus](https://github.com/Salahbendary/Stop-Watch-System/blob/main/MiniProject2SalahKhaled/MiniProject2_SalahKhaled.pdsprj)

---

This repository provides a comprehensive guide to creating a stop-watch system using the ATmega16 microcontroller. By following the provided instructions and code, you can successfully build and understand the project, gaining valuable insights into using peripherals for embedded system development.

Please note that this guide assumes a basic understanding of electronics and programming and is intended for educational purposes.

Explore the exciting world of embedded systems! 🚀

Last updated: 2023-08-15 10:30:00 CET
