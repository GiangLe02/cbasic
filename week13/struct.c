#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct product_s {
    char *name;
    int price;
} *product_t;

typedef struct giatri_s{
    char *name;
    int number;
} *giatri_t;
typedef struct order_s
{
    char *id;
    int k;
    giatri_t *giatri;
}*order_t;

typedef struct ouput{
    char *id;
    int price;
} *output_t;

void add_output(output_t n, char *id, int price){
    n-> id = strdup(id);
    n-> price = price;
}
void print_output(output_t n){
    printf("\t%s\t%d\n",n->id,n->price);
}