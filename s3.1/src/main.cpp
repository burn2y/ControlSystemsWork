#include <mbed.h>

int main() {
    AnalogIn  left(A0);
    AnalogIn right(A1);
    while(1) {
        printf(" Left dial %f \n",  left.read() );
        printf("Right dial %f \n", right.read() );
        wait( 1.0 );
    }
}
