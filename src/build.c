#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

#include "bobuilder.h"

typedef struct {
  const char **sprite;
  unsigned int width;
  unsigned int height;
} model_t;

typedef struct {
  unsigned int width;
  unsigned int height;
  char *buff;
} canvas_t;

canvas_t create_canvas(unsigned int width, unsigned int height) {
  canvas_t canvas = { .width = width, .height = height };

  unsigned int buff_size = width * height * sizeof(char);
  canvas.buff = (char *) malloc(buff_size);

  for (unsigned int i = 0; i < buff_size; i++) {
    if ((i + 1) % width == 0) {
      canvas.buff[i] = '\n';
      continue;
    }

    canvas.buff[i] = ' ';
  }

  canvas.buff[buff_size - 1] = 0;

  return canvas;
}

void draw_canvas(unsigned int x, unsigned int y, model_t model, canvas_t canvas) {
  for (unsigned int my = 0, index = y * canvas.width + x; my < model.height; my++, index += canvas.width) {
    strncpy(&canvas.buff[index], model.sprite[my], model.width);
  }
}

void free_canvas(canvas_t canvas) {
  free(canvas.buff);
}

// Sprites and Models
const char *house_roof_sprite[] = {
    "   ___    ",
    "  /,-,\\  ",
    " / |_| \\ ",
    "/_______\\"
};

const model_t house_roof_model = {
  .sprite = house_roof_sprite,
  .width  = 9,
  .height = 4
};

const char *house_window_sprite[] = {
  "|,^, ,^,|",
  "||_| |_||"
};


const model_t house_window_model = {
  .sprite = house_window_sprite,
  .width  = 9,
  .height = 2
};

const char *house_door_sprite[] = {
  "|    ,-,|",
  "|    | ||",
  "'======='"
};

const model_t house_door_model = {
  .sprite = house_door_sprite,
  .width  = 9,
  .height = 3
};

const char *garage_sprite[] = {
  " _________ ",
  "/,-------,\\",
  "||       ||",
  "||   -   ||",
  "'========='"
};

const model_t garage_model = {
  .sprite = garage_sprite,
  .width  = 11,
  .height = 5
};

int main(int argc, char **argv) {
  house_t house;
  read(STDIN, &house, sizeof(house));

  unsigned int canvas_width = house_roof_model.width + (garage_model.width * house.garages) + 1;
  unsigned int canvas_height = house_roof_model.height + house_door_model.height + (house_window_model.height * house.floors);

  canvas_t canvas = create_canvas(canvas_width, canvas_height);

  unsigned int x = 0, y = 0;

  // Drawing garages
  unsigned int garage_y = canvas_height - garage_model.height;
  for (unsigned int i = 0; i < house.garages; i++) {
    draw_canvas(x, garage_y, garage_model, canvas);
    x += garage_model.width;
  }

  // Drawing house itself
  draw_canvas(x, y, house_roof_model, canvas);

  y += house_roof_model.height;

  for (unsigned int floor = 0; floor < house.floors; floor++) {
    draw_canvas(x, y, house_window_model, canvas);
    y += house_window_model.height;
  }

  draw_canvas(x, y, house_door_model, canvas);

  printf("%s\n", canvas.buff);

  free_canvas(canvas);

  return 0;
}
