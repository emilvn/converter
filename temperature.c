#include<stdio.h>

void display_temperature_intro();
void display_temperature_menu();
float fahrenheit_to_celsius(float);
float celsius_to_fahrenheit(float);

void temperature_main()
{
    display_temperature_intro();

    char choice;

    while (
        choice != 'b'
    )
    {
        display_temperature_menu();
        choice = get_choice();

        char *from;
        char *to;
        float value;
        float result;
        switch (choice)
        {
        case 'f':
            from = "Fahrenheit";
            to = "Celsius";
            value = get_value(from);
            result = fahrenheit_to_celsius(value);
            print_result(value, result, from, to);
            break;
        case 'c':
            from = "Celsius";
            to = "Fahrenheit";
            value = get_value(from);
            result = celsius_to_fahrenheit(value);
            print_result(value, result, from, to);
            break;
        default:
            break;
        }
    }
}

void display_temperature_intro()
{
    printf("---------------------------------\n");
    printf("Welcome to temperature converter.\n");
    printf("---------------------------------\n");
}

void display_temperature_menu()
{
    const char *opts[] = {"fahrenheit to celsius", "celsius to fahrenheit", "back"};
    display_menu("Select temperature conversion", opts, 3);
}

float fahrenheit_to_celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

float celsius_to_fahrenheit(float cels)
{
    return (cels / (5.0 / 9.0)) + 32.0;
}


