#include <msp430.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Library/LunchboxCommon.h>

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    int j;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main(void)
{   //! Stop Watchdog (Not recommended for code in production
//and devices working in field)
    WDTCTL = WDTPW | WDTHOLD;

    initialise_SerialPrint_on_lunchbox();
    while (1)
    {
        uint8_t x = 2;
        uint8_t y = 4;
        uint8_t z = 8;
        printf("\r\n x value \t");
        decToBinary(x);
        printf("\r\n y value \t");
        decToBinary(y);
        printf("\r\n z value \t");
        decToBinary(z);
        printf("\r\n\r\n\r\n");
        printf("\r\n Bitwise operators in C \r\n");
        uint8_t a = 0b01000100; //68 or 0x44
        uint8_t b = 0b00100100; //36 or 0x24
        printf("\r\n value of a & b \t");
        decToBinary(a & b);
        printf("\r\n value of a | b \t");
        decToBinary(a | b);
        printf("\r\n value of a<<1 \t");
        decToBinary(a << 1);
        printf("\r\n value of a^b \t");
        decToBinary(a ^ b);
        printf("\r\n value of 1<<3 \t");
        decToBinary(1 << 3);
        printf("\r\n value of a|(1<<4) \t");
        decToBinary(a | (1 << 4));
        printf("\r\n\r\n\r\n");
        unsigned long delay;
        for (delay = 0; delay < 60000; delay++)
            ;
    }
}
