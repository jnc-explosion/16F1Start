/* 
 * File:   random_TMR0.h
 * Author: meumeumeucar
 *
 * Created on May 4, 2023, 11:45 PM
 */

#ifndef RANDOM_TMR0_H
#define	RANDOM_TMR0_H

#include<stdlib.h>
#include"mcc_generated_files/tmr0.h"

#ifdef	__cplusplus
extern "C" {
#endif

    uint16_t random_TMR0(unsigned char reSeed) {
        static unsigned char now = 0;
        if (now % reSeed == 0)srand(TMR0_ReadTimer());
        now++;
        return rand();
    }


#ifdef	__cplusplus
}
#endif

#endif	/* RANDOM_TMR0_H */

