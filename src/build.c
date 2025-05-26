#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

#include "bobuilder.h"

int main(int argc, char **argv) {
  house_t house;

  read(STDIN, &house, sizeof(house));

  char *house_roof = "   ___\n"
                     "  /,-,\\\n"
                     " / |_| \\\n"
                     "/_______\\\n";
  int house_roof_len = strlen(house_roof);

  char *house_window = "|,^, ,^,|\n"
                       "||_| |_||\n";
  int house_window_len = strlen(house_window);

  char *house_door = "|    ,-,|\n"
                     "|    |º||\n";
  int house_door_len = strlen(house_door);

  char *house_floor = "'======='\n";
  int house_floor_len = strlen(house_floor);

  int house_len = house_roof_len + (house_window_len * house.floors) + house_door_len + house_floor_len;
  char *house_str = (char *) malloc(house_len);

  strcat(house_str, house_roof);

  for (unsigned int i = 0; i < house.floors; i++) {
    strcat(house_str, house_window);
  }

  strcat(house_str, house_door);
  strcat(house_str, house_floor);

  printf("%s\n", house_str);

  free(house_str);
  return 0;
}
