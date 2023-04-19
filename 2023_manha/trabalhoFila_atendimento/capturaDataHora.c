#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("Agora: %02d/%02d/%d %02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
}