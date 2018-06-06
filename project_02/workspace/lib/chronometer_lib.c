#include <time.h>
#include <sys/time.h>
#include <stdio.h>

void time_measurement(void * (* function)(void * args), void * args)
{
  clock_t processor_time_used_0;
  clock_t processor_time_used_1;

  processor_time_used_0 = clock();

  void * r = function(args);

  processor_time_used_1 = clock();

  printf("Tempo user: %f segundos\n", (double) (processor_time_used_1 -
              processor_time_used_0)/CLOCKS_PER_SEC);
}
