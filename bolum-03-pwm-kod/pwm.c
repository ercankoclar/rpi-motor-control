#include <stdio.h>
#include <unistd.h>
#include <pigpiod_if2.h>

// Motor
#define ENA  12   // PWM0
#define IN1  17
#define IN2  27

#define PWM_FREQ 1000
#define PWM_RANGE 255

int main(void)
{
    // pigpiod'ye baglan
    int pi = pigpio_start(NULL, NULL);
    if (pi < 0) {
        printf("pigpiod baglantisi basarisiz!\n");
        return 1;
    }

    // GPIO modlari
    set_mode(pi, ENA, PI_OUTPUT);
    set_mode(pi, IN1, PI_OUTPUT);
    set_mode(pi, IN2, PI_OUTPUT);

    // PWM ayarlari
    set_PWM_frequency(pi, ENA, PWM_FREQ);
    set_PWM_range(pi, ENA, PWM_RANGE);

    // Guvenli baslangic
    set_PWM_dutycycle(pi, ENA, 0);
    gpio_write(pi, IN1, 0);
    gpio_write(pi, IN2, 0);

    // Ileri
    gpio_write(pi, IN1, 1);
    gpio_write(pi, IN2, 0);

    // HEMEN calissin (soft-start yok)
    for (int duty = 0; duty <= 255; duty += 25)
    {
        set_PWM_dutycycle(pi, ENA, duty);
        usleep(100000); // 100 ms
    }

    sleep(2);

    // Geri
    gpio_write(pi, IN1, 0);
    gpio_write(pi, IN2, 1);

    // HEMEN calissin (soft-start yok)
    for (int duty = 0; duty <= 255; duty += 25)
    {
        set_PWM_dutycycle(pi, ENA, duty);
        usleep(100000); // 100 ms
    }

    sleep(2);


    // Dur
    set_PWM_dutycycle(pi, ENA, 0);
    gpio_write(pi, IN1, 0);
    gpio_write(pi, IN2, 0);

    pigpio_stop(pi);
    return 0;
}
