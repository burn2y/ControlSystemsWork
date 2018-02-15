#include <mbed.h>
#include <C12832.h>

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);
AnalogIn left(A0);
AnalogIn right(A1);

int main()
{
    int counter = 0;

    lcd.cls();
    lcd.rect(0,0,127,31,1);

    while(true) {   // this is the third thread
      lcd.locate(2,3);
      lcd.printf("Left Dial: %2f", left.read());
      lcd.locate(2,12);
      lcd.printf("Right Dial: %2f", right.read());

    }
}
