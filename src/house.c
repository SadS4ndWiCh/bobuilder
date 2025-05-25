#include <stdio.h>
#include <unistd.h>

#include "bobuilder.h"

int main(int argc, char **argv) {
  house_t house = { 1 };

  write(STDOUT, &house, sizeof(house));
  return 0;
}
