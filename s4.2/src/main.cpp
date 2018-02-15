#include <mbed.h>
#include <FXOS8700Q.h>

I2C i2c(PTE25, PTE24);
FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);
FXOS8700QMagnetometer  mag(i2c, FXOS8700CQ_SLAVE_ADDR1);

Serial pc(USBTX, USBRX);

int main(void)
{
    motion_data_units_t acc_data, mag_data;

    acc.enable();
    mag.enable();

    while (true) {
        acc.getAxis(acc_data);
        mag.getAxis(mag_data);
        pc.printf("ACC: X=%+1.3f Y=%+1.3f Z=%+1.3f \t",
                  acc_data.x, acc_data.y, acc_data.z);
        pc.printf("MAG: X=%+4.1f Y=%+4.1f Z=%+4.1f\n",
                  mag_data.x, mag_data.y, mag_data.z);
        wait(0.5);
    }
}
