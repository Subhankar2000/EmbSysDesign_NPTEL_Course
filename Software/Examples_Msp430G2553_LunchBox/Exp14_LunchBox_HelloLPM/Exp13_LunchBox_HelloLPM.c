#include <msp430.h> 

#define SW      BIT3                    // Switch -> P1.3
#define RED     BIT7                    // Red LED -> P1.7

/*@brief entry point for the code*/
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; //! Stop Watch dog (Not recommended for code in production and devices working in field)

    P1DIR |= RED;                       // Set LED pin -> Output
    P1DIR &= ~SW;                       // Set SW pin -> Input
    P1REN |= SW;                        // Enable Resistor for SW pin
    P1OUT |= SW;                        // Select Pull Up for SW pin
    P1OUT &= ~RED;                      // Turn RED LED off
    P1IES &= ~SW;                       // Select Interrupt on Rising Edge
    P1IE |= SW;                         // Enable Interrupt on SW pin

    unsigned int i;

    while (1)
    {
        //__bis_SR_register(GIE);           // Enable CPU Interrupt
        __bis_SR_register(LPM4_bits + GIE); // Enter LPM4 and Enable CPU Interrupt

        P1OUT ^= RED;                       // Toggle RED LED
        for (i = 0; i < 20000; i++)
            ;
    }
}

/*@brief entry point for switch interrupt*/
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    __bic_SR_register_on_exit(LPM4_bits + GIE);   // Exit LPM4 on return to main
    P1IFG &= ~SW;                                   // Clear SW interrupt flag
}
