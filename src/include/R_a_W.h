#ifndef R_A_W_H_
#define R_A_W_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "menu.h"

#define MAX_TEXT_SIZE 431

char *read_from_file(char *file_name);
void print_text(char *text, uint16_t text_size);
void menu_equalization(uint8_t new_line, char *cur_menu);
void print_mistake_text(char *correct, char *incorrect, uint16_t text_size);

#endif //R_A_W_H_
