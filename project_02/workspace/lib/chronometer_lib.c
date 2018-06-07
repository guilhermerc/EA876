#include <time.h>
#include <sys/time.h>
#include <stdio.h>

void time_measurement(void * (* function)(void * args), void * args)
{
  clock_t processor_time_used_0;
  clock_t processor_time_used_1;
  
  struct timeval real_time_0;
  struct timeval real_time_1;
  struct timeval real_time_diff;

  gettimeofday(&real_time_0, NULL);
  processor_time_used_0 = clock();

  void * r = function(args);

  gettimeofday(&real_time_1, NULL);
  processor_time_used_1 = clock();

  timersub(&real_time_1, &real_time_0, &real_time_diff);

  int time_diff_ms = (real_time_diff.tv_sec * 1000) +
      (real_time_diff.tv_usec / 1000);

  printf("Tempo gasto:\t\t\t%d ms\n", time_diff_ms);
}
