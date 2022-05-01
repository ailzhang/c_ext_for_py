#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int my_sum(int num_numbers, int *numbers) {
#if 0
  long start, end;
  struct timeval timecheck;
  gettimeofday(&timecheck, NULL);
  start = (long)timecheck.tv_sec * 1000 * 1000 + (long)timecheck.tv_usec;
#endif
  int i;
  int sum = 0;
  for (i = 0; i < num_numbers; i++) {
    sum += numbers[i];
  }
#if 0
  gettimeofday(&timecheck, NULL);
  end = (long)timecheck.tv_sec * 1000 * 1000 + (long)timecheck.tv_usec;
  printf("%ld us elapsed\n", (end - start));
#endif
  return sum;
}
