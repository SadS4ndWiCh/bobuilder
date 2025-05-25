#include <stdlib.h>
#include <unistd.h>

#include "bobuilder.h"

int main(int argc, char **argv) {
  house_t house;
  read(STDIN, &house, sizeof(house));

  if (argc > 1) {
    unsigned int floors = atoi(argv[1]);
    house.floors = floors;
  } else {
    house.floors += 1;
  }

  write(STDOUT, &house, sizeof(house));
  return 0;
}
