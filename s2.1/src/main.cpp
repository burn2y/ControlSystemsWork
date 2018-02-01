#include <mbed.h>

DigitalOut   red(LED_RED);
DigitalOut green(LED_GREEN);

void on(void)
{
    red.write(0);
    puts("rising 0->1");
}
void off(void)
{
    red.write(1);
    puts("falling 1->0");
}

int main() {
    InterruptIn  left(SW2);
    InterruptIn right(SW3);

    left.rise(on);
    right.fall(off);
    while(1) {
        /* GNDN */
    }
}
