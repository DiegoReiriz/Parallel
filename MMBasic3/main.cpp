#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <cstring>
#include "read_data.hh"

int main() {
    struct timeval inicio, final;
    double tiempo;
    gettimeofday(&inicio,NULL);

    int gris[256];
    memset(&gris,0,256);

    int w,h,i;

    unsigned char* data = importPGM("pavia_university_2048.pgm", w,h);

    int total = w*h;

    for (i =0; i < total; i++)
        gris[data[i]]++;

    for (i =0; i < 256; i++)
        gris[i]=gris[i]/total;

    gettimeofday(&final,NULL);

    tiempo = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);

     printf("time: %.50lf \t",tiempo);

    for(int i = 0;i<256;i++)
        printf("%d ",gris[i]);

    free(data);
    return 0;
}
