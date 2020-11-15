#ifndef _LUNCHBOX_COMMON_H
#define _LUNCHBOX_COMMON_H
/**
 * @brief
 * preprocessor directive for uart
 * For overriding the fputc() and fputs() functions
 **/
#define UART_PRINTF                         // used for conditional compilation

#define PI 3.1415                           // to replace value at time of compilation

void initialise_SerialPrint_on_lunchbox(); // function prototyping

#define SerialPrint(x) printf(x)            //function like macros

#endif // !_LUNCHBOX_COMMON_H


