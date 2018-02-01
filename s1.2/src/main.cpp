#include <mbed.h>

#include <stdbool.h>

int main() {
    bool flashing = false;

    DigitalOut red(PTB22);
    DigitalIn  btn(PTC6);

    while(1) {
        if( btn.read() ) flashing = true;
            else         flashing = false;

        printf("button %d\n", btn.read() );
        if(flashing){
            red.write(0);
            wait(0.5);
            red.write(1);
            wait(0.5);
        }else{
            red.write(1);
            wait(1);
        }
    }
}
