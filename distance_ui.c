#include<stdio.h>
#include "distance.c"

void display_distance_intro();
void display_distance_menu1();
void display_distance_menu2(char);

void distance_main()
{
    display_distance_intro();

    char convert_from;
    while (convert_from != 'b'){
        int restart_loop = 0;
        display_distance_menu1();
        convert_from = get_choice();

        char* from;
        char* to;
        switch (convert_from)
        {
        case 'a':
            from = "Astronomical Units";
            break;
        case 'l':
            from = "Light Years";
            break;
        case 'p':
            from = "Parsec";
            break;
        default:
            restart_loop = 1;
            break;
        }

        if(restart_loop == 1){
            continue;
        }

        char convert_to = '0'; //resetting to 0 so it doesnt stay as b

        while (convert_to != 'b'){
            restart_loop = 0;
            display_distance_menu2(convert_from);
            convert_to = get_choice();

            switch (convert_to)
            {
            case 'a':
                to = "Astronomical Units";
                break;
            case 'l':
                to = "Light Years";
                break;
            case 'p':
                to = "Parsec";
                break;
            default:
                restart_loop = 1;
                break;
            }
            if(restart_loop == 1){
                continue;
            }

            float value = get_value(from);
            float result = get_distance_conversion(convert_from, convert_to, value);

            print_result(value, result, from, to);
            return;
        }
    }
}

void display_distance_intro()
{
    printf("---------------------------------\n");
    printf("Welcome to distance converter.\n");
    printf("---------------------------------\n");
}

void display_distance_menu1()
{
    const char *opts[] = {"astronomical units", "light years", "parsec", "back"};
    display_menu("Select a distance unit to convert", opts, 4);
}

void display_distance_menu2(char from)
{   
    switch (from)
    {
    case 'a':
        const char *aopts[] = {"light years", "parsec", "back"};
        display_menu("Select the unit you want to convert to", aopts, 3);
        break;
    case 'l':
        const char *lopts[] = {"astronomical units", "parsec", "back"};
        display_menu("Select the unit you want to convert to", lopts, 3);
        break;
    case 'p':
        const char *popts[] = {"light years", "parsec", "back"};
        display_menu("Select the unit you want to convert to", popts, 3);
        break;
    default:
        break;
    }
}