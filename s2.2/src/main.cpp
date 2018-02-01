#include <mbed.h>

DigitalOut blue(LED_BLUE);

Ticker  pit;

void flash(void) {
   static unsigned int phase=0;

   if(phase==0) blue.write(0); /* on */
   if(phase==1) blue.write(1); /* off */

   phase++;
   if(phase==3) phase=0;
}

int main(void) {
  pit.attach(flash,0.5);
  while(1);
}
