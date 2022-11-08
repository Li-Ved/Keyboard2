#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "scene.h"
#include "struct_profile.h"


// colors
#define KMAG2 "\x1B[32m" 
#define KMAG4 "\x1B[34m"
#define KMAG5 "\x1B[35m" 
#define KMAG6 "\x1B[36m" 
#define KMAG9 "\x1B[39m" 

int choosen_action();
void intro(int intro_variant);
void fast_intro(int intro_variant);
int menu(Profile *profile, int intro_variant);

#endif //MENU_H_
