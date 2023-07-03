#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float a;
    float b;
    char name;
} complex;

void read_comp(complex *comp, float a, float b);
void print_comp(complex comp);
void add_comp(complex comp1, complex comp2);
void sub_comp(complex comp1, complex comp2);
void mult_comp_real(complex comp, float real);
void mult_comp_img(complex comp, float img);
void mult_comp_comp(complex comp1, complex comp2); 
void abs_comp(complex comp);
