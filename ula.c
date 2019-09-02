/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2019 Michael Ortmann */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

int main()
{
  uint8_t i[7];

  if (getrandom(&i, sizeof i, 0) != sizeof i) {
    perror("getrandom()");
    return EXIT_FAILURE;
  }

  printf("fd%x:%x%x:%x%x:%x%x::/64\n", i[0], i[1], i[2], i[3], i[4], i[5],
         i[6]);
}
