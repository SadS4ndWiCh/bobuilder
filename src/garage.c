#include <stdlib.h>
#include <unistd.h>

#include "bobuilder.h"

int main(int argc, char **argv) {
  house_t house;
  read(STDIN, &house, sizeof(house));

  if (argc == 2) {
    unsigned int garages = atoi(argv[1]);
    house.garages = garages;
  } else {
    house.garages += 1;
  }

  write(STDOUT, &house, sizeof(house));
  return 0;
}
