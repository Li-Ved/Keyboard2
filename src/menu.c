#include <stdio.h>
#include "include/mode.h"
#include "include/menu.h"
#include "include/training.h"
#include "include/rating.h"

static char keyboard[16][102] = {
    {"_____________________________________________________________________________________________"},
};

int choosen_action(int intro_variant)
{
    int choice = 0;

    printf("\nInput your choice: ");

    while (scanf("%d", &choice) != 1)
    {
        scanf("%*[^\n]");
        system("clear");
        fast_intro(intro_variant);
        printf(KMAG9 "\n\t1.Training    2.Scene    3.Rival    4.Rating    5.Help    6.Exit");
        printf(KMAG9 "\nInput your choice: ");
    }

    return choice;
}

void fast_intro(int intro_variant)
{
    system("clear");
    int i, k;

    for (i = 0; i < 16; i++)
    {
        for (k = 0; k < 102; k++)
        {
            printf(KMAG9 "%c", keyboard[i][k]);
        }
        printf("\n");
    }

    return;
}

void intro(int intro_variant)
{
    system("clear");
    int i, j, t;
    int step;

    j = 101;

    for (j = 101; j >= 0; j--)
    {                    
        system("clear"); 
        step = 102 - j;  
                         
        for (i = 0; i < 16; i++)
        {
            for (t = step; t > 0; t--)
            {
                printf(KMAG9 "%c", keyboard[i][102 - t]);
            }
            printf("\n");
        }

        usleep(20000);
    }
}

int menu(Profile *profile, int intro_variant) //Ïîñëå âûáîðà äåéñòâèÿ çàíîâî âûçûâàåòñÿ ìåíþ.
{
    int choice = 0;

    system("clear");

    fast_intro(profile->interface);
    printf(KMAG9 "\n\t1.Training    2.Scene    3.Rival    4.Rating     5.Help    6.Exit");
    choice = choosen_action(intro_variant);

    while (choice < 0 || choice > 6)
    {
        system("clear");
        fast_intro(profile->interface);
        printf(KMAG9 "\n\t1.Training    2.Scene    3.Rival    4.Rating     5.Help    6.Exit");
        choice = choosen_action(profile->interface);
    }

    if (choice == 1) //For training
    {
        system("clear");
        train(profile, intro_variant);
    }
    if (choice == 2) //Scene
    {
        scene(profile);
    }
    if (choice == 3) //For rival
    {
        system("clear");
        mode(profile);
    }
    if (choice == 4) //For rating
    {
        output();
    }

    if (choice == 5)
    {
        system("clear");
        fast_intro(profile->interface);
        printf(KMAG9 "\n|||The game should help you learn how to type quickly on the keyboard.");
        printf(KMAG9 "\n|||To select an action, enter a number from the selection presented");
        printf(KMAG9 "\n|||Wait...\n");
        usleep(7000000);
    }

    if (choice == 6)
    {
        free(profile);
        exit(0);
    }

    menu(profile, profile->interface);

    return 0;
}
