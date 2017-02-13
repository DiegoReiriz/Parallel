#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "read_data.hh"

#define N 2048

int main() {

    struct timeval inicio, final;
    double tiempo;
    gettimeofday(&inicio,NULL);

    double* A = importDOUBLE("A.txt",N,N);
    double* b = importDOUBLE("b.txt",N,N);
    double* res = (double *) malloc( sizeof(double) * N);

    gettimeofday(&final,NULL);
    int offset=0;
    int k;
    int i;
    for(k=0; k<N;k++){
        offset+=N;

        for(i=0; i<N; i+=4)
            res[k]+=A[offset+i]*b[i];
		res[k]+=A[offset+i]*b[i+1];
		res[k]+=A[offset+i]*b[i+2];
		res[k]+=A[offset+i]*b[i+3];
    }


    tiempo = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);

    printf("time: %.50lf \t",tiempo);
    for(int i = 0;i<N;i++)
        printf("%e     ",res[i]);

    free(A);
    free(b);
    free(res);
    return 0;
}
