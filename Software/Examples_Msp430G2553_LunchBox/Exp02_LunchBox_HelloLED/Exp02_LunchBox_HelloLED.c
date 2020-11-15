#include <msp430.h>

/*@brief entry point for the code*/
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;       //! Stop Watchdog (Not recommended for code in production and devices working in field)

    //P1DIR |= BIT7;
    P1DIR |= 0x80;                  // Set P1.7 to output direction

    //P1OUT |= BIT7;
      P1OUT |= 0x80;                  // Set P1.7 to HIGH voltage
                                      // As the LED is in Active High configuration physically on board, so setting the pin to HIGH will make it glow

    //P1OUT &=~ BIT7;
    //P1OUT &=~ 0x80;                  // Set P1.7 to LOW voltage
                                      // As the LED is in Active High configuration physically on board, so setting the pin to LOW will make it OFF
    return 0;
}
