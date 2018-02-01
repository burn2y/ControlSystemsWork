#include <mbed.h>

int main() {

    DigitalOut red(PTB22);

    while(1) {
      red.write(0);
      wait(0.5);
      red.write(1);
      wait(0.5);
    }
}
