#include "mbed.h"

DigitalIn fire(D4);
DigitalOut green(D9,1);

PwmOut speaker(D6);

int main()
{
    while (1) {
        float f;
        green.write(1);
        for (f=20.0; f<20.0e3; f+=100) {
            speaker.period(1.0/f);
            speaker.write(0.5);
            wait(0.1);
        }
        speaker.write(0.0);
        green.write(0);
        while(!fire);
    }
}
