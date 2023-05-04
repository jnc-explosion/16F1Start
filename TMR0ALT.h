/* 
 * File:   TMR0delay.h
 * Author: meumeumeucar
 *
 * Created on May 5, 2023, 12:50 AM
 */

#ifndef TMR0ALT_H
#define	TMR0ALT_H

#ifdef	__cplusplus
extern "C" {
#endif

    bool tmr0val = false;

    void TMR0isrFlip() {
        tmr0val = !tmr0val;
    }

    bool isTMR0Sta() {
        return tmr0val;
    }


#ifdef	__cplusplus
}
#endif

#endif	/* TMR0ALT_H */

