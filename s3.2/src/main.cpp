#include "mbed.h"

PwmOut red(D5);

int main()
{
    red.period_ms(10);/* suitably fast 100Hz */

    while(1){
        /* ramp up from 0 to 100% */
        float duty;
        for( duty=0 ; duty<1.0 ; duty+=0.01 ) {
            red.write(duty);
            wait_ms(100);
        }
    }
}
