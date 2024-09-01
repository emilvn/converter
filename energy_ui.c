#include<stdio.h>
#include "energy.c"

void display_energy_intro();
void display_energy_menu1();
void display_energy_menu2(char);

void energy_main()
{
    display_energy_intro();

    char convert_from;
    while (convert_from != 'b'){
        int restart_loop = 0;
        display_energy_menu1();
        convert_from = get_choice();

        char* from;
        char* to;
        switch (convert_from)
        {
        case 'h':
            from = "Hartree";
            break;
        case 'e':
            from = "Electron Volts";
            break;
        case 'k':
            from = "kcal/mol";
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
            display_energy_menu2(convert_from);
            convert_to = get_choice();

            switch (convert_to)
            {
            case 'h':
                to = "Hartree";
                break;
            case 'e':
                to = "Electron Volts";
                break;
            case 'k':
                to = "kcal/mol";
                break;
            default:
                restart_loop = 1;
                break;
            }
            if(restart_loop == 1){
                continue;
            }

            float value = get_value(from);
            float result = get_energy_conversion(convert_from, convert_to, value);

            print_result(value, result, from, to);
            return;
        }
    }
}

void display_energy_intro()
{
    printf("---------------------------------\n");
    printf("Welcome to energy converter.\n");
    printf("---------------------------------\n");
}

void display_energy_menu1()
{
    const char *opts[] = {"hartree", "electron volts", "kcal/mol", "back"};
    display_menu("Select a energy unit to convert", opts, 4);
}

void display_energy_menu2(char from)
{   
    switch (from)
    {
    case 'h':
        const char *aopts[] = {"electron volts", "kcal/mol", "back"};
        display_menu("Select the unit you want to convert to", aopts, 3);
        break;
    case 'e':
        const char *lopts[] = {"hartree", "kcal/mol", "back"};
        display_menu("Select the unit you want to convert to", lopts, 3);
        break;
    case 'k':
        const char *popts[] = {"hartree", "electron volts", "back"};
        display_menu("Select the unit you want to convert to", popts, 3);
        break;
    default:
        break;
    }
}