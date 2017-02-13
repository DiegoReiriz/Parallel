
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#define N 1000000

int main() {

     //Calcular el valor de π mediante la fórmula de Bailey-Borwein-Plouffe1
    struct timeval inicio, final;
    double tiempo;
    gettimeofday(&inicio,NULL);

    double pi=0;
    int x;

    for(int k = 0; k < N; k++){
        x = 8*k;
        pi += (1.0F/pow(16,k)) * ((4.0F/(x+1))-(2.0F/(x+4))-(1.0F/(x+5))-(1.0F/(x+6)));
    }

    gettimeofday(&final,NULL);
    tiempo = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);

    printf("time: %.50lf \t- value: %.50lf",tiempo,pi);

    return 0;
}