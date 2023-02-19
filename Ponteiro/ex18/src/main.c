/*
Implemente uma funcao que calcule a area da superfıcie e o volume de uma esfera de
raio R.
A area da superfıcie e o volume sao dados, respectivamente, por:
A = 4 ∗ p ∗ R^2
V = 4/3 ∗ p ∗ R^3
*/
#include <stdio.h>
#include <math.h>

#define pi 3.1415

void calc_esfera(float R, float *area, float *volume);

int main() {
    float r = 15.43;
    float ar;
    float vol;

    calc_esfera(r, &ar, &vol);
    printf("A area e o volume da esfera de raio %.2f sao %.2f e %.2f, respectivamente\n", r, ar, vol);

    return 0;
}

void calc_esfera(float R, float *area, float *volume) {
    *area = 4.0 * pi * (float)pow(R, 2);
    *volume = (4.0/3.0) * pi * (float)pow(R, 3);
}