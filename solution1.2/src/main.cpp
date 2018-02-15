#include <mbed.h>

#include <stdbool.h>

enum { Red, Green, Blue};
DigitalOut LED[] = {
  DigitalOut(PTB22,1),
  DigitalOut(PTE26,1),
  DigitalOut(PTC21,1)
};

void LEDon(int n) {
  LED[n].write(0);
}
void LEDoff(int n) {
  LED[n].write(1);
}

enum { Btn1, Btn2 };
DigitalIn buttons[] = {
  DigitalIn(SW2), DigitalIn(SW3)
};

bool ispressed(int b) {
  return !(buttons[b].read());
}

int main() {
    bool flashing = false;


    while(1) {
        if(ispressed(Btn1) ) flashing = !flashing;

        if(flashing){
            LEDon(Red);
            wait(0.05);
            LEDoff(Red);
            wait(0.05);
        }else{
            LEDoff(Red);
            wait(1);
        }
    }
}
