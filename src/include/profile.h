#ifndef PROFILE_H_
#define PROFILE_H_

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "R_a_W.h"
#include "struct_profile.h"

#define NAME_SIZE 16 

char *create_nickname(uint8_t fail_name);
char *verification_name(char *name);
Profile *add_profile();
Profile *find_profile();
void write_profile(Profile *profile);
Profile *sing_in();

#endif //PROFILE_H_
