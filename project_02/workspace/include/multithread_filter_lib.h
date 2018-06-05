#ifndef MULTITHREAD_FILTER_LIB_H 
#define MULTITHREAD_FILTER_LIB_H 

#include <stdint.h>

uint8_t N_THREADS;
// This is the global variable that holds the number of threads to be created.
// This number is chosen as an argument of main call.

void multithread_filter();

#endif
