#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

/* This macro defines a printing format for complex numbers */
#define PRINT_FORMAT(element1, element2) printf("\n%.2f + (%.2f)i\n", element1, element2)

#define COMMAND_PRINT_FORMAT1(command, element1) printf("\n%s %c\n", command, element1)
#define COMMAND_PRINT_FORMAT21(command, element1, element2) printf("\n%s %c, %c\n", command, element1, element2)
#define COMMAND_PRINT_FORMAT22(command, element1, element2) printf("\n%s %c, %.2f\n", command, element1, element2)
#define COMMAND_PRINT_FORMAT3(command, element1, element2, element3) printf("\n%s %c, %.2f, %.2f\n", command, element1, element2, element3)

/* This function reads two floating point numbers and stores them as the real (a) and imaginary (b) parts of a complex number */
void read_comp(complex *comp, float a, float b)
{
    COMMAND_PRINT_FORMAT3("read_comp", (*comp).name, a, b);
    (*comp).a = a;
    (*comp).b = b;
}

/* This function prints the real and imaginary parts of a complex number in a specified format using the PRINT_FORMAT macro */
void print_comp(complex comp)
{
    COMMAND_PRINT_FORMAT1("print_comp", comp.name);
    PRINT_FORMAT(comp.a, comp.b);
}

/* This function adds two complex numbers and prints the result in a specified format using the PRINT_FORMAT macro */
void add_comp(complex comp1, complex comp2)
{
    COMMAND_PRINT_FORMAT21("add_comp", comp1.name, comp2.name);
    PRINT_FORMAT((comp1.a + comp2.a), (comp1.b + comp2.b));
}

/* This function subtracts two complex numbers and prints the result in a specified format using the PRINT_FORMAT macro */
void sub_comp(complex comp1, complex comp2)
{
    COMMAND_PRINT_FORMAT21("sub_comp", comp1.name, comp2.name);
    PRINT_FORMAT((comp1.a - comp2.a), (comp1.b - comp2.b));
}

/* This function multiplies a complex number by a real number and prints the result in a specified format using the PRINT_FORMAT macro */
void mult_comp_real(complex comp, float real)
{
    COMMAND_PRINT_FORMAT22("mult_comp_real", comp.name, real);
    PRINT_FORMAT((comp.a * real), (comp.b * real));
}

/* This function multiplies a complex number by an imaginary number and prints the result in a specified format using the PRINT_FORMAT macro */
void mult_comp_img(complex comp, float img)
{
    COMMAND_PRINT_FORMAT22("mult_comp_img", comp.name, img);
    PRINT_FORMAT((-1 * img * comp.b), (comp.a * img));
}

/* This function multiplies two complex numbers and prints the result in a specified format using the PRINT_FORMAT macro */
void mult_comp_comp(complex comp1, complex comp2)
{
    COMMAND_PRINT_FORMAT21("mult_comp_comp", comp1.name, comp2.name);
    PRINT_FORMAT(((comp1.a * comp2.a) - (comp1.b * comp2.b)), ((comp1.a * comp2.b) + (comp1.b * comp2.a)));
}

/* This function calculates the magnitude (absolute value) of a complex number and prints the result */
void abs_comp(complex comp)
{
    COMMAND_PRINT_FORMAT1("abs_comp", comp.name);
    printf("\n%.2f\n", sqrt(pow(comp.a, 2) + pow(comp.b, 2)));
}
