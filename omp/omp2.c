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

    printf("Hello there!, I'm the master of the universe!\n");

    /* Fork a team of threads giving them their own copies of variables */
    #pragma omp parallel num_threads(4) private(nthreads, tid)
    {
        char hostname[1024];
        /* Obtain thread number */
        tid = omp_get_thread_num();
        gethostname(hostname, 1024);
        printf("Hello World from thread = %d at machine [%s]\n", tid, hostname);

        /* Only master thread does this */
        #pragma omp master 
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d at machine [%s]\n", nthreads, hostname);
        }
    }  /* All threads join master thread and disband */
    printf("Good bye from the the master of the universe!\n");
}
