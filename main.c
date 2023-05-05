/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1509
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "toner.h"
#include "random_TMR0.h"
#include "mcc_generated_files/tmr0.h"

/*
                         Main application
 */
#define SEGIC 15
#define ANTI_CHATA_MSEC 50
#define FIRSTVELO 50
#define FIRSTLIFE 3

//global variables
uint16_t cursor = 0x01;
uint16_t target = 0x01;
uint16_t point = 0;
uint16_t velocity = FIRSTVELO;
int8_t life = FIRSTLIFE;
bool inloop = false;
bool gameflag = false;
bool brightflip = false;
bool great = false;
bool shiftToL = false;

void R_BTN_run(void(*ffptr)(), void(*lfptr)()) {
    static bool rflag = false;
    if (!R_BTN_PORT && !rflag) {
        ffptr();
        rflag = true;
        __delay_ms(ANTI_CHATA_MSEC); //anti chata
    } else if (R_BTN_PORT && rflag) {
        lfptr();
        rflag = false;
        __delay_ms(ANTI_CHATA_MSEC); //anti chata
    }
    return;
}

void B_BTN_run(void(*ffptr)(), void(*lfptr)()) {
    static bool bflag = false;
    if (!B_BTN_PORT && !bflag) {
        ffptr();
        bflag = true;
        __delay_ms(ANTI_CHATA_MSEC); // anti chata
    } else if (B_BTN_PORT && bflag) {
        lfptr();
        bflag = false;
        __delay_ms(ANTI_CHATA_MSEC); //anti chata
    }
}

void flashLED(unsigned int disp, int segs) {
    for (unsigned char i = 0; i < segs; i++) {
        LED_CLK_PORT = 0;
        LED_DAT_PORT = (disp & 0b1);
        disp >>= 1;
        LED_CLK_PORT = 1;
    }
    LED_CLK_PORT = 0;
    LED_STB_PORT = 1;
    LED_STB_PORT = 0;
}

void shiftL(void) {
    if (cursor & 0b1) cursor == 0b10000000000;
    cursor >>= 1;
    if (cursor & 0b10000000000) cursor = 0b1;
    tone(800);
    return;
}

void shiftR(void) {
    if (cursor & 0b1) cursor = cursor | 0b100000000000;
    cursor <<= 1;
    if (cursor & 0b10000000000) cursor = cursor | 0b1;
    tone(800);
    return;
}

void shiftInv() {
    shiftToL = !shiftToL;
    return;
}

void flashing(void) {
    static uint16_t bdisp = 0;
    uint16_t nowdisp = (cursor << 5) | (0b11100 >> (FIRSTLIFE - life)) & 0b11100 | great << 1 | gameflag;
    if (nowdisp != bdisp)flashLED(nowdisp, SEGIC);
    bdisp = nowdisp;
    return;
}

//void submit(void) {
//    inloop = false;
//    __delay_ms(50);
//    return;
//}

//void genHit(void) {
//    static uint8_t hitper = SEGIC - 1;
//    uint16_t hitrange = 0b1111111111 >> (SEGIC - hitper); // get right aligned data
//    target = hitrange << (random_TMR0(8) % (SEGIC + 1 - hitper)); // randomise shift to left
//    if (hitper != 1 && random_TMR0(8) % 2)hitper--; // random percent decrease
//    return;
//}

void dispExact(void) {
    noTone();
    flashLED(0, SEGIC);
    __delay_ms(500);
    for (uint8_t i = 0, m = 0b11000; i < 6; i++, m = ~m) {
        flashLED(0b100000000100000 | (m & 0b000000000011100 | 0b00100), SEGIC);
        tone(200);
        __delay_ms(100);
        noTone();
        __delay_ms(100);
    }
    for (uint8_t i = 0, m = 0b10000; i < 6; i++, m = ~m) {
        flashLED(0b011000011000000 | (m & 0b000000000011100 | 0b01100), SEGIC);
        tone(800);
        __delay_ms(100);
        noTone();
        __delay_ms(100);
    }
    __delay_ms(10);
    flashLED(0b000111100000000, SEGIC);
    tone(1600);
    __delay_ms(1000);
    for (uint16_t i = 0, disp = 0b000111100000000; i < 8; i++, disp = ~disp) {
        flashLED((disp & 0b000111100000011) | 0b11100, SEGIC);
        noTone();
        __delay_ms(200);
        tone(1600);
        __delay_ms(200);
    }
    noTone();
    return;
}

void start(void) {
    tone(523);
    __delay_ms(250);
    noTone();
    __delay_ms(125);
    tone(523);
    __delay_ms(250);
    tone(587);
    __delay_ms(250);
    tone(391);
    __delay_ms(500);
    inloop = true;
    gameflag = true;
    return;
}

void collect(void) {
    for (uint8_t i = 0; i < 10; i++) {
        great = !great;
        flashing();
        tone(2000);
        __delay_ms(17);
        great = !great;
        flashing();
        tone(1000);
        __delay_ms(17);
        great = !great;
        flashing();
        tone(4000);
        __delay_ms(16);
    }
    noTone();
    if (velocity != 1)velocity--;
    point++;

    return;
}

void incollect(void) {
    for (uint8_t i = 0; i < 10; i++) {
        tone(500);
        __delay_ms(50);
        tone(200);
        __delay_ms(50);
    }
    return;
}

void checkHit(void) {
    if (cursor & 0b0001111000) {
        collect();
        if (great && life < 3) {
            life++;
        }
        great = !great;
    } else {
        incollect();
        great = false;
        if (cursor & 0b1000000001) {
            life -= 2;
        } else {
            life--;
        }
        if (life < 0)gameflag = false;
    }
}

void result() {
    flashLED((0b1111111111000 >> (SEGIC - (point / 10) % 10) & 0b111111111100000), SEGIC);

    // song: turip
    //    tone(523);
    //    __delay_ms(250);
    //    tone(587);
    //    __delay_ms(250);
    //    tone(659);
    //    __delay_ms(250);
    //    noTone();
    //    __delay_ms(250);
    //    tone(523);
    //    __delay_ms(250);
    //    tone(587);
    //    __delay_ms(250);
    //    tone(659);
    //    __delay_ms(250);
    //    noTone();
    //    __delay_ms(250);
    //    tone(784);
    //    __delay_ms(250);
    //    tone(659);
    //    __delay_ms(250);
    //    tone(587);
    //    __delay_ms(250);
    //    tone(523);
    //    __delay_ms(250);
    //    tone(587);
    //    __delay_ms(250);
    //    tone(659);
    //    __delay_ms(250);
    //    tone(523);
    //    __delay_ms(500);

    // DPRK funeral song
    tone(523);
    __delay_ms(1000);
    tone(698);
    __delay_ms(1500);
    tone(523);
    __delay_ms(500);
    tone(698);
    __delay_ms(500);
    tone(784);
    __delay_ms(500);
    tone(831);
    __delay_ms(500);
    noTone();
    __delay_ms(200);
    tone(698);
    __delay_ms(200);
    tone(784);
    __delay_ms(2000);

    noTone();
    __delay_ms(1000);
    point = 0;
    return;
}

void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //    INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //    INTERRUPT_PeripheralInterruptDisable();

    tone(2000);
    __delay_ms(100);
    tone(1000);
    __delay_ms(100);
    noTone();

    while (1) { // roulette
        //reset
        target = 0;
        cursor = 0;
        velocity = FIRSTVELO;
        life = FIRSTLIFE;
        point = 0;
        great = false;
        shiftToL = false;
        flashLED(cursor, SEGIC);

        // asobi (waiting)
        while (!gameflag) {
            R_BTN_run(start, NULL);
            B_BTN_run(start, NULL);
            if (cursor > 32767) {
                cursor >>= random_TMR0(32) % 16;
            } else {
                cursor += random_TMR0(32) % 27;
                cursor <<= random_TMR0(32) % 2;
            }
            tone(cursor & 0xFFF);
            __delay_ms(25);
            noTone();
            __delay_ms(25);
            flashLED(cursor, SEGIC);
        }
        noTone();

        // game start
        cursor = 0;
        dispExact();

        while (gameflag) { // in game
            cursor = 0b1000000000; // reset segment, align left
            while (R_BTN_PORT) { // rouletting
                B_BTN_run(shiftInv, NULL);
                if (shiftToL) {
                    shiftL();
                } else {
                    shiftR();
                }
                flashing();
                tone(800);
                for (uint16_t i = 0; i < velocity; i++)__delay_ms(1);
                noTone();
                for (uint16_t i = 0; i < velocity; i++)__delay_ms(1);
            }
            for (uint16_t t = velocity; t <= 100; t += random_TMR0(8) % 15) {
                if (shiftToL) {
                    shiftL();
                } else {
                    shiftR();
                }
                flashing();
                tone(800);
                for (uint16_t i = 0; i < t; i++) __delay_ms(1);
                noTone();
                for (uint16_t i = 0; i < t; i++) __delay_ms(1);
            }
            checkHit();
        }
        result();
    }
}
/**
 End of File
 **/
