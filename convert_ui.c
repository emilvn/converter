#include<stdio.h>

void display_main_intro()
{
    printf("-------------------------\n");
    printf("Welcome to unit converter\n");
    printf("-------------------------\n");
}
void display_menu(char title[], const char *opts[], int n)
{
    printf("-------------------------\n");
    printf("%s\n", title);
    for (int i = 0; i < n; i++){
        printf("(%c) %s\n", opts[i][0], opts[i]);
    }
    printf("-------------------------\n");
}

void display_main_menu()
{
    const char *opts[] = {"distance", "weight", "energy", "temperature", "close"};
    display_menu("Select unit type", opts, 5);
}


char get_choice()
{
    printf("Choose: ");
    char choice;
    scanf(" %c", &choice);
    return choice;
}

float get_value(char text[])
{
    printf("Input value in %s: ", text);
    float value;
    scanf(" %f", &value);
    return value;
}

void print_result(float value, float result, char from[], char to[])
{
    printf("---------------------------------------\n");
    printf("%.2f %s is %.4f %s\n", value, from, result, to);
    printf("---------------------------------------\n");
}