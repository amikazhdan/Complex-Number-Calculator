/*
 * This program performs various operations on complex numbers.
 * The complex numbers are represented by the characters A-F.
 * The operations include:
 * read_comp - reads two floating point numbers to form a complex number.
 * print_comp - prints a complex number.
 * add_comp - adds two complex numbers.
 * sub_comp - subtracts two complex numbers.
 * mult_comp_real - multiplies a complex number by a real number.
 * mult_comp_img - multiplies a complex number by an imaginary number.
 * mult_comp_comp - multiplies two complex numbers.
 * abs_comp - calculates the absolute value of a complex number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "complex.h"

#define NAME_LENGTH 10
#define COMMAND_LENGTH 15

complex *get_comp_by_name(char name, complex *complex_vars[], int num_vars);
int includesComma(char array[], int size);
int commandExists(char *array[], int size, char command[]);
void takeCareOfExtraneousText(void);

int main(void)
{
    /* Initialize complex variables*/
    complex A = {0.0, 0.0, 'A'};
    complex B = {0.0, 0.0, 'B'};
    complex C = {0.0, 0.0, 'C'};
    complex D = {0.0, 0.0, 'D'};
    complex E = {0.0, 0.0, 'E'};
    complex F = {0.0, 0.0, 'F'};

    /* Declare and initialize all other variables*/
    complex *complex_vars[6];
    int num_vars;
    char command[COMMAND_LENGTH];
    char name_str1[NAME_LENGTH];
    char name_str2[NAME_LENGTH];
    char name_str3[NAME_LENGTH];
    float current_num1;
    float current_num2;
    complex *current_comp1;
    complex *current_comp2;
    char name1;
    char name2;
    char temp;
    char *commandArr[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};

    /* Assign the addresses of complex variables to the complex_vars array */
    complex_vars[0] = &A;
    complex_vars[1] = &B;
    complex_vars[2] = &C;
    complex_vars[3] = &D;
    complex_vars[4] = &E;
    complex_vars[5] = &F;

    num_vars = sizeof(complex_vars) / sizeof(complex *);

    printf("\nPlease enter command in this way: 'command parameter1, parameter2'\n");
    printf("\nThe options are:\n* read_comp(Complex, num, num)\n* print_comp(Complex)\n* add_comp(Complex, Complex)\n* sub_comp(Complex, Complex)\n* mult_comp_real(Complex, num)\n* mult_comp_img(Complex, num)\n* mult_comp_comp(Complex, Complex)\n* abs_comp(Complex)\n* stop\n\n");

    while (1)
    {
        if (scanf("%s", command) == EOF)
        {
            break;
        }
        if (includesComma(command, COMMAND_LENGTH))
        {
            while (getchar() != '\n')
            {
            }
            printf("Illegal comma\n");
            continue;
        }
        if (!commandExists(commandArr, 9, command))
        {
            while (getchar() != '\n')
            {
            }
            continue;
        }
        if (strcmp(command, "stop") == 0)
        {
            takeCareOfExtraneousText();
            break;
        }
        if (scanf("%s", name_str1) == EOF)
        {
            printf("Missing parameter\n");
            break;
        }

        if ((name1 = name_str1[0]) == '\n') /*no text after command*/
        {
            printf("Missing parameter\n");
            continue;
        }

        current_comp1 = get_comp_by_name(name1, complex_vars, num_vars);
        if (!current_comp1) /*that complex number does not exist*/
        {
            while (getchar() != '\n')
            {
            }
            printf("Undefined complex variable:\n");
            continue;
        }

        if (strcmp(command, "print_comp") == 0)
        {
            print_comp(*current_comp1);
            takeCareOfExtraneousText();
            continue;
        }
        else if (strcmp(command, "abs_comp") == 0)
        {
            abs_comp(*current_comp1);
            takeCareOfExtraneousText();
            continue;
        }

        if (!includesComma(name_str1, NAME_LENGTH))
        { /*checks if previous parameter had a comma at the end and if not it swallows the comma that does exist. if two commas exist it will say so and move to the next line*/
            while ((temp = getchar()) != '\n' || temp != ',')
            {
            }
            if (temp == '\n')
            { /*no comma was reached*/
                printf("Missing comma\n");
                continue;
            }
        }

        if (scanf("%s", name_str2) == EOF)
        {
            printf("Missing parameter\n");
            break;
        }
        else if ((name2 = name_str2[0]) == '\n')
        {
            printf("Missing parameter\n");
            continue;
        }

        if (isdigit(name_str2[0]) || isdigit(name_str2[1])) /*two options in case of negative number*/
        {
            current_num1 = atof(name_str2);

            if (strcmp(command, "mult_comp_img") == 0)
            {
                mult_comp_img(*current_comp1, current_num1);
                takeCareOfExtraneousText();
                continue;
            }
            else if (strcmp(command, "mult_comp_real") == 0)
            {
                mult_comp_real(*current_comp1, current_num1);
                takeCareOfExtraneousText();
                continue;
            }
        }
        else
        {
            current_comp2 = get_comp_by_name(name2, complex_vars, num_vars);
            if (!current_comp2)
            {
                while (getchar() != '\n')
                {
                }
                if (strcmp(command, "mult_comp_real") == 0 || strcmp(command, "mult_comp_img") == 0)
                { /*current parameter does not fit the command*/
                    printf("Invalid parameter - not a number\n");
                }
                else
                {
                    printf("Unknown complex variable name:\n");
                }
                continue;
            }

            if (strcmp(command, "add_comp") == 0)
            {
                add_comp(*current_comp1, *current_comp2);
                takeCareOfExtraneousText();
                continue;
            }
            if (strcmp(command, "sub_comp") == 0)
            {
                sub_comp(*current_comp1, *current_comp2);
                takeCareOfExtraneousText();
                continue;
            }
            if (strcmp(command, "mult_comp_comp") == 0)
            {
                mult_comp_comp(*current_comp1, *current_comp2);
                takeCareOfExtraneousText();
                continue;
            }
        }

        if (!includesComma(name_str2, NAME_LENGTH))
        {
            while ((temp = getchar()) != '\n' || temp != ',')
            {
            }
            if (temp == '\n')
            {
                printf("Missing comma\n");
                continue;
            }
        }

        if (scanf("%s", name_str3) == EOF)
        {
            printf("Missing parameter\n");
            break;
        }
        else if (name_str3[0] == '\n')
        {
            printf("Missing parameter\n");
            continue;
        }
        else if (!isdigit(name_str3[0]) && !isdigit(name_str3[1]))
        {
            while (getchar() != '\n')
            {
            }
            printf("Invalid parameter - not a number\n");
            continue;
        }
        current_num2 = atof(name_str3);
        if (strcmp(command, "read_comp") == 0)
        {
            read_comp(current_comp1, current_num1, current_num2);
            takeCareOfExtraneousText();
            continue;
        }
    }
    return 0;
}

/*Takes a char and checks in the premade array of complex numbers if a complex number of that name exists. If it does the function will return a pointer to that number and if not it will return NULL.*/
complex *get_comp_by_name(char name, complex *complex_vars[], int num_vars)
{
    int i;
    for (i = 0; i < num_vars; i++)
    {
        if (complex_vars[i]->name == name)
        {
            return complex_vars[i];
        }
    }
    return NULL;
}

/*Takes a string and checks if it has a comma in it. returns 1 if it has 1 comma, 0 if none and prints message and returns 0 if string has 2 commas.*/
int includesComma(char array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == ',')
        {
            if (array[++i] == ',')
            {
                printf("Multiple consecutive commas\n");
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

/*Takes a string and array of strings and checks checks wether the string exist in the array. Returns 1 if yes, print message and returns 0 if no.*/
int commandExists(char *array[], int size, char command[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(array[i], command) == 0)
        {
            return 1;
        }
    }
    printf("Undefined command name\n");
    return 0;
}

/*Swallows all text until new line, if text does exist prints message.*/
void takeCareOfExtraneousText(void)
{
    int flag;
    char temp;
    flag = 0;
    while ((temp = getchar()) != '\n')
    {
        if (temp != ' ' && temp != '\t'){
            flag = 1;
        }
    }
    if (flag)
    {
        printf("Extraneous text after end of command\n");
    }
}
