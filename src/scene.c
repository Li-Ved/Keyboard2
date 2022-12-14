#include "include/scene.h"

char choice;

void scene(Profile *profile)
{
    fast_intro(profile->interface);
    menu_equalization(1, "choice one variant");
    menu_equalization(1, "1.Easy        2.medium        3.insane        4.back        5.close");
    scanf("%hhd", &choice);

    if (choice == 1)
    {
        easy(profile);
    }

    if (choice == 2 && profile->levels_passed < 3)
    {
        cannot("complexity", profile, 0);
    }

    if (choice == 2 && profile->levels_passed >= 3)
    {
        medium(profile);
    }

    if (choice == 3 && profile->levels_passed < 6)
    {
        cannot("complexity", profile, 0);
    }

    if (choice == 3 && profile->levels_passed >= 6)
    {
        insane(profile);
    }

    if (choice == 4)
    {
        fast_intro(profile->interface);
        menu(profile, 1);
    }

    if (choice == 5)
    {
        free(profile);
        exit(0);
    }
    else
    {
        scanf("%*[^\n]");
        scene(profile);
    }
}

void easy(Profile *profile)
{
    while ((choice = getchar()))
    {
        fast_intro(profile->interface);
        menu_equalization(1, "choice one variant");
        menu_equalization(1, "1.first level      2.second level      3.third level      4.back      5.close");

        if (choice == '1')
        {
            char *text = read_from_file("./data/L1.txt");
            play_level(profile, text, 2, 157, 1, 157);
            free(text);
            easy(profile);
        }

        if (choice == '2' && profile->levels_passed < 1)
        {
            cannot("level", profile, 1);
        }

        if (choice == '2' && profile->levels_passed >= 1)
        {
            char *text = read_from_file("./data/L2.txt");
            play_level(profile, text, 2, 166, 2, 166);
            free(text);
            easy(profile);
        }

        if (choice == '3' && profile->levels_passed < 2)
        {
            cannot("level", profile, 1);
        }

        if (choice == '3' && profile->levels_passed >= 2)
        {
            char *text = read_from_file("./data/L3.txt");
            play_level(profile, text, 2, 170, 3, 198);
            free(text);
            easy(profile);
        }

        if (choice == '4')
        {
            scene(profile);
        }

        if (choice == '5')
        {
            free(profile);
            exit(0);
        }
    }
}

void medium(Profile *profile)
{
    while ((choice = getchar()))
    {
        fast_intro(profile->interface);
        menu_equalization(1, "choice one variant");
        menu_equalization(1, "1.fourth level      2.fifth level      3.sixth level      4.back      5.close");

        if (choice == '1')
        {
            char *text = read_from_file("./data/L4.txt");
            play_level(profile, text, 1, 150, 4, 170);
            free(text);
            medium(profile);
        }

        if (choice == '2' && profile->levels_passed < 4)
        {
            cannot("level", profile, 2);
        }

        if (choice == '2' && profile->levels_passed >= 4)
        {
            char *text = read_from_file("./data/L5.txt");
            play_level(profile, text, 1, 168, 5, 188);
            free(text);
            medium(profile);
        }

        if (choice == '3' && profile->levels_passed < 5)
        {
            cannot("level", profile, 2);
        }

        if (choice == '3' && profile->levels_passed >= 5)
        {
            char *text = read_from_file("./data/L6.txt");
            play_level(profile, text, 1, 138, 6, 158);
            free(text);
            medium(profile);
        }

        if (choice == '4')
        {
            scene(profile);
        }

        if (choice == '5')
        {
            free(profile);
            exit(0);
        }
    }
}

void insane(Profile *profile)
{
    while ((choice = getchar()))
    {
        fast_intro(profile->interface);
        menu_equalization(1, "choice one variant");
        menu_equalization(1, "1.seventh level      2.eighth level      3.ninth level      4.back      5.close");

        if (choice == '1')
        {
            char *text = read_from_file("./data/L7.txt");
            play_level(profile, text, 0, 257, 7, 287);
            free(text);
            insane(profile);
        }

        if (choice == '2' && profile->levels_passed < 7)
        {
            cannot("level", profile, 2);
        }

        if (choice == '2' && profile->levels_passed >= 7)
        {
            char *text = read_from_file("./data/L8.txt");
            play_level(profile, text, 0, 700, 8, 283);
            free(text);
            insane(profile);
        }

        if (choice == '3' && profile->levels_passed < 8)
        {
            cannot("level", profile, 2);
        }

        if (choice == '3' && profile->levels_passed >= 8)
        {
            char *text = read_from_file("./data/L9.txt");
            play_level(profile, text, 0, 379, 9, 429);
            free(text);
            insane(profile);
        }

        if (choice == '4')
        {
            scene(profile);
        }

        if (choice == '5')
        {
            free(profile);
            exit(0);
        }
    }
}

void play_level(Profile *profile, char *text, uint8_t max_mistake, long int max_time, uint8_t level_number, uint16_t text_size)
{
    level_manual(profile, max_mistake);

    system("clear");
    scanf("%*[^\n]");
    fast_intro(profile->interface);
    print_text(text, text_size);

    char ch;
    int mistake = -1, i = 0;
    long int start_time, end_time;
    char *input = malloc(sizeof(char) * text_size);

    start_time = time(NULL);
    ch = getchar();

    while (text[i] != '\0')
    {
        ch = getchar();
        input[i] = ch;

        if (ch == '\n')
        {
            fast_intro(1);
            printf("Press enter");
            scanf("%*[^\n]");
            break;
        }

        if (text[i] != ch && ch != '\n')
        {
            mistake++;

            if (mistake == max_mistake)
            {
                input[i + 1] = '\0';

                while ((ch = getchar() != '1'))
                {
                    fast_intro(profile->interface);
                    printf(KMAG4 "\nYou made more mistake then was decide\nPut \'1\' for continue\n\n");
                }

                fast_intro(profile->interface);
                print_text(text, text_size);
                print_mistake_text(text, input, i);

                free(input);
                return;
            }
        }

        i++;
    }

    end_time = time(NULL);

    if ((end_time - start_time) >= max_time)
    {
        while ((ch = getchar() != '1'))
        {
            fast_intro(profile->interface);
            printf(KMAG4 "\nYou did go beyond the time frame\nPut \'1\' for continue\n");
        }

        free(input);
        return;
    }

    mistake = mistake + (text_size - i);
    mistake_test(profile, mistake, max_mistake, level_number, 0);
    fast_intro(profile->interface);

    if (mistake > 0)
    {
        print_text(text, text_size);
        print_mistake_text(text, input, i);
        free(input);
    }
}

void level_manual(Profile *profile, uint8_t max_mistake)
{
    while ((choice = getchar() != '1'))
    {
        fast_intro(profile->interface);
        printf("\n");
        printf(KMAG4 "Enter text, new string equal space, so use space!\n");

        if (max_mistake == 2)
        {
            printf("You can make 2 mistake\n");
        }

        if (max_mistake == 1)
        {
            printf("You can make 1 mistake\n");
        }

        if (max_mistake == 0)
        {
            printf("You cannot make mistake\n");
        }

        printf("Enter '1' for continue\n");
    }
}

int mistake_test(Profile *profile, int mistake, uint8_t max_mistake, uint8_t level_number, uint8_t test)
{

    char ch;

    if (mistake <= max_mistake)
    {
        if (level_number > profile->levels_passed && profile->levels_passed != 8)
        {
            profile->levels_passed = profile->levels_passed + 1;
            if (test == 0)
            {
                ch = '0';
                ch = getchar();

                while (ch != '1')
                {
                    fast_intro(profile->interface);
                    printf(KMAG5 "\nYou win, you make %d mistake, you open %d level\nPut \'1\' for continue\n", mistake + 1, profile->levels_passed + 1);
                    ch = getchar();
                }
            }

            return 0;
        }

        if ((profile->levels_passed != 8 && level_number != 9) || (profile->levels_passed == 9))
        {
            if (test == 0)
            {
                fast_intro(profile->interface);
                ch = '0';
                ch = getchar();

                while (ch != '1')
                {
                    fast_intro(profile->interface);
                    printf(KMAG5 "\nYou win, you make %d mistake, you completed level\nPut \'1\' for continue\n", mistake + 1);
                    ch = getchar();
                }
            }

            return 0;
        }
        else if (profile->levels_passed == 8 && level_number == 9)
        {
            profile->levels_passed = profile->levels_passed + 1;

            if (test == 0)
            {
                ch = '0';
                ch = getchar();

                while (ch != '1')
                {
                    printf(KMAG5 "\n??ongratulations you passed game!\nPut \'1\' for continue");
                    ch = getchar();
                }
            }

            return 0;
        }
    }
    else
    {
        if (test == 0)
        {
            while ((ch = getchar() != '1'))
            {
                fast_intro(profile->interface);
                printf(KMAG4 "\nYou made more mistake then was decide, \nput \'1\' for continue\n\n\n");
            }
        }

        return 1;
    }

    return 1;
}

//
void cannot(char *current, Profile *profile, uint8_t complexity)
{
    if (strcmp(current, "complexity") == 0)
    {
        while ((choice = getchar()))
        {
            fast_intro(profile->interface);
            printf(KMAG2);
            menu_equalization(1, "You cannot choice that level");
            printf(KMAG9);
            menu_equalization(1, "1.continue      2.menu      3.close");

            if (choice == '1')
            {
                scene(profile);
            }

            if (choice == '2')
            {
                fast_intro(profile->interface);
                menu(profile, 1);
            }

            if (choice == '3')
            {
                exit(0);
                free(profile);
            }
            else
            {
                cannot("complexity", profile, 0);
            }
        }

        return;
    }

    if (strcmp(current, "level") == 0)
    {
        while ((choice = getchar()))
        {
            fast_intro(profile->interface);
            printf(KMAG2);
            menu_equalization(1, "You cannot choice that level");
            printf(KMAG9);
            menu_equalization(1, "1.continue      2.menu      3.close");

            if (choice == '1')
            {
                if (complexity == 1)
                {
                    easy(profile);
                }

                if (complexity == 2)
                {
                    medium(profile);
                }

                if (complexity == 3)
                {
                    insane(profile);
                }
            }

            if (choice == '2')
            {
                fast_intro(profile->interface);
                menu(profile, 1);
            }

            if (choice == '3')
            {
                exit(0);
                free(profile);
            }
            else
            {
                cannot("level", profile, complexity);
            }
        }
    }
}
