#include <mbed.h>

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

int main() {


    while(1) {
      int k;
      for( k=0 ; k<3 ; k++){
        LEDon(k);
        wait(0.5);
        LEDoff(k);
      }
    }
}
