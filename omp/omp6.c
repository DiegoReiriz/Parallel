/*
 * PSMM [G4011449] Labs
 * Last update: 10/02/2017
 * 
 * Author: Pablo Quesada Barriuso
 *
 * Credits: Blaise Barney  5/99         
 *
 * This work is licensed under a Creative Commons
 * Attribution-NonCommercial-ShareAlike 4.0 International.
 * http:// https://creativecommons.org/licenses/by-nc-sa/4.0/
 * 
 * THE AUTHOR MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) 
{
    int nthreads, tid;


    int array[2048*2048]; // 4 threads * 10 iterations per thread
    int i=0;

    /* Fork a team of threads giving them their own copies of variables */
    #pragma omp parallel for num_threads(4) shared(array) schedule(static,4)
    for(i=0;i<2048*2048;i++)
	array[i] = omp_get_thread_num();


    printf("thread asignation: ");
    for(i=0;i<2048*2048;i++)
        printf("%d ",array[i]);

    printf("\n");

}
