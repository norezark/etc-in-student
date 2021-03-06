#include <stdio.h>
#include <math.h>

#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define G4 392.00
#define A4 440.00
#define B4 493.88
#define C5 523.25

#define LEN 8
#define A 20000
#define SAMPLE_RATE 44100

int main(void){
    double t, y, f[] = {C4, D4, E4, F4, E4, D4, C4, 0,
                        E4, F4, G4, A4, G4, F4, E4};
    int onkai = sizeof(f)/sizeof(f[0]);
    double theta = 0;

    for(t=0; t<=LEN*SAMPLE_RATE; t++){
        y = A * sin(theta);
        printf("%d\n%d\n", (short)y, (short)y);
        theta += 2.0 * M_PI * f[(int)(t/LEN/SAMPLE_RATE*onkai)] / SAMPLE_RATE;
    }

    return 0;
}
