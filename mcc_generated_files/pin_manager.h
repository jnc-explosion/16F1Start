/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1509
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set R_BTN aliases
#define R_BTN_TRIS                 TRISCbits.TRISC0
#define R_BTN_LAT                  LATCbits.LATC0
#define R_BTN_PORT                 PORTCbits.RC0
#define R_BTN_ANS                  ANSELCbits.ANSC0
#define R_BTN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define R_BTN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define R_BTN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define R_BTN_GetValue()           PORTCbits.RC0
#define R_BTN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define R_BTN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define R_BTN_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define R_BTN_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set B_BTN aliases
#define B_BTN_TRIS                 TRISCbits.TRISC2
#define B_BTN_LAT                  LATCbits.LATC2
#define B_BTN_PORT                 PORTCbits.RC2
#define B_BTN_ANS                  ANSELCbits.ANSC2
#define B_BTN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define B_BTN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define B_BTN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define B_BTN_GetValue()           PORTCbits.RC2
#define B_BTN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define B_BTN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define B_BTN_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define B_BTN_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LED_STB aliases
#define LED_STB_TRIS                 TRISCbits.TRISC3
#define LED_STB_LAT                  LATCbits.LATC3
#define LED_STB_PORT                 PORTCbits.RC3
#define LED_STB_ANS                  ANSELCbits.ANSC3
#define LED_STB_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_STB_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_STB_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_STB_GetValue()           PORTCbits.RC3
#define LED_STB_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_STB_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_STB_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_STB_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LED_DAT aliases
#define LED_DAT_TRIS                 TRISCbits.TRISC4
#define LED_DAT_LAT                  LATCbits.LATC4
#define LED_DAT_PORT                 PORTCbits.RC4
#define LED_DAT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_DAT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED_DAT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED_DAT_GetValue()           PORTCbits.RC4
#define LED_DAT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED_DAT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set LED_CLK aliases
#define LED_CLK_TRIS                 TRISCbits.TRISC5
#define LED_CLK_LAT                  LATCbits.LATC5
#define LED_CLK_PORT                 PORTCbits.RC5
#define LED_CLK_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_CLK_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_CLK_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_CLK_GetValue()           PORTCbits.RC5
#define LED_CLK_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_CLK_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/