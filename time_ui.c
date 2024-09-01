#include<stdio.h>
#include "time.c"

void display_time_intro();
void display_time_menu1();
void display_time_menu2(char);

void time_main()
{
    display_time_intro();

    char convert_from;
    while (convert_from != 'b'){
        int restart_loop = 0;
        display_time_menu1();
        convert_from = get_choice();

        char* from;
        char* to;
        switch (convert_from)
        {
        case 'm':
            from = "minutes";
            break;
        case 'w':
            from = "weeks";
            break;
        case 'y':
            from = "years";
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
            display_time_menu2(convert_from);
            convert_to = get_choice();

            switch (convert_to)
            {
            case 'm':
                to = "minutes";
                break;
            case 'w':
                to = "weeks";
                break;
            case 'y':
                to = "years";
                break;
            default:
                restart_loop = 1;
                break;
            }
            if(restart_loop == 1){
                continue;
            }

            float value = get_value(from);
            float result = get_time_conversion(convert_from, convert_to, value);

            print_result(value, result, from, to);
            return;
        }
    }
}

void display_time_intro()
{
    printf("---------------------------------\n");
    printf("Welcome to time converter.\n");
    printf("---------------------------------\n");
}

void display_time_menu1()
{
    const char *opts[] = {"minutes", "weeks", "years", "back"};
    display_menu("Select a time unit to convert", opts, 4);
}

void display_time_menu2(char from)
{   
    switch (from)
    {
    case 'm':
        const char *aopts[] = {"weeks", "years", "back"};
        display_menu("Select the unit you want to convert to", aopts, 3);
        break;
    case 'w':
        const char *lopts[] = {"minutes", "years", "back"};
        display_menu("Select the unit you want to convert to", lopts, 3);
        break;
    case 'y':
        const char *popts[] = {"minutes", "weeks", "back"};
        display_menu("Select the unit you want to convert to", popts, 3);
        break;
    default:
        break;
    }
}