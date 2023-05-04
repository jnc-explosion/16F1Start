/* 
 * File:   toner.h
 * Author: meumeumeucar
 *
 * Created on May 4, 2023, 10:37 PM
 */

#ifndef TONER_H
#define	TONER_H

#include<xc.h>
#include<stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

    void tone(unsigned int freq) {
        N1OE = true;
        freq = freq / 8;
        NCO1INCL = freq % 256;
        NCO1INCH = freq / 256;
        return;
    }

    void noTone(void) {
        N1OE = false;

        return;
    }

#ifdef	__cplusplus
}
#endif

#endif	/* TONER_H */

