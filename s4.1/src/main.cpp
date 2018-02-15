#include <mbed.h>

Serial pc(USBTX, USBRX);

int main(void)
{
    int q;
    char c;
    int n;
    pc.puts("\e[4mHello\e[m is the K64F\n");
    while (true) {
      for( q=0 ; q<11 ; q++) {
        pc.printf("%2d... ", q);

        wait(1.0);
      }
      pc.putc('\n');
      pc.printf("Press any key to continue...\n");
      c = pc.getc();
      pc.printf("(%c) Enter a number:", c);
      pc.scanf("%d", &n);
      pc.printf("Countdown ");
      for( q=n ; q>0 ; q-=1) {
        pc.printf("%d. ", q);
        wait(1);
      }
      pc.puts("go\n");
    }
}
