#include <mbed.h>
#include <C12832.h>

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);

int main()
{
    int j=0;
    lcd.cls();
    lcd.locate(0,0);
    lcd.printf("mbed application shield!");
    lcd.locate(0,10);
    lcd.printf("char %dx%d : %dx%d pixels",
               lcd.columns(), lcd.rows(),
               lcd.width(), lcd.height() );
    lcd.circle(100, 20, 10, 1);

    while(true) {
        lcd.locate(0,20);
        lcd.printf("Counting : %4d",j);
        j++;
        wait(1.0);
    }
}
