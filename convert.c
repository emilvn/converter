#include<stdio.h>
#include "convert_ui.c"
#include "distance_ui.c"
#include "energy_ui.c"
#include "time_ui.c"

int main()
{
    display_main_intro();
    char choice;

    while (choice != 'c') 
    {
        display_main_menu();
        choice = get_choice();
        switch (choice)
        {
        case 'd':
            distance_main();
            break;
        case 'e':
            energy_main();
            break;
        case 't':
            time_main();
            break;
        default:
            break;
        }
    }
    printf("Exiting\n");
    return 0;
}