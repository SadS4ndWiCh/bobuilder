#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "bobuilder.h"

int main(int argc, char **argv) {
  house_t house;

  read(STDIN, &house, sizeof(house));

  char house_str[64] = {0};
  strcpy(house_str,  " / \\\n/   \\\n");
  for (unsigned int i = 0; i < house.floors; i++) {
    strcat(house_str, "|   |\n");
  }

  printf("%s\n", house_str);

  return 0;
}
