#include <msp430.h>

#define SW1      BIT0                    // Switch -> P1.0
#define SW2      BIT1                    // Switch -> P1.1
#define LED1     BIT3                    // LED-1 LED -> P1.3
#define LED2     BIT5                    // LED-2 LED -> P1.5

/*@brief entry point for the code*/
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; //! Stop Watchdog (Not recommended for code in production and devices working in field)

    P1DIR |= LED1;                     // Set LED1 pin -> Output
    P1DIR |= LED2;                     // Set LED2 pin -> Output
    P1DIR &= ~SW1;                       // Set SW1 pin -> Input
    P1DIR &= ~SW2;                       // Set SW2 pin -> Input
    P1REN |= (SW1 + SW2);                  // Enable Resistors for SW1 & SW2 pin
    P1OUT |= (SW1 + SW2);                    // Select Pull Up for SW1 & SW2 pin

    P1IES |= (SW1 + SW2);              // Select both Interrupts on Falling Edge
    P1IE |= (SW1 + SW2);                 // Enable Interrupts on SW1 and SW2 pin

    __bis_SR_register(GIE);             // Enable CPU Interrupt

    while (1)
        ;
}

/*@brief entry point for switch interrupt*/
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if (P1IFG & SW1)                     // If SW1 is Pressed
    {
        P1OUT ^= LED1;                   // Toggle LED-1 LED
        volatile unsigned long i;
        for (i = 0; i < 100; i++)
            ; //delay -> here in proteus a very short type of delay is required to just help toggle the LED, else it does not work, it is also there in hello switch, or anywhere where delay is prohibited
        P1IFG &= ~SW1;                   // Clear SW1 interrupt flag
    }
    else if (P1IFG & SW2)                     // If SW2 is Pressed
    {
        P1OUT ^= LED2;                   // Toggle LED-2 LED
        volatile unsigned long i;
        for (i = 0; i < 100; i++)
            ; //delay -> here in proteus a very short type of delay is required to just help toggle the LED, else it does not work, it is also there in hello switch, or anywhere where delay is prohibited
        P1IFG &= ~SW2;                   // Clear SW2 interrupt flag
    }
}
