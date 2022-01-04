#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#include "cgen.h"
#include "ext/io.h"
#include "function.c"

int main(int argc,char *argv[]){
    if(argc != 3){
        printf("Usage: '/prog products.txt orders.txt'\n");
        return 1;
    }

    FILE *inp1 = fopen(argv[1],"r");
    if(!inp1){
        printf("Loi doc tep %s!\n",argv[1]);
        return 1;
    }
    FILE *inp2 = fopen(argv[2],"r");
    if(!inp2){
        printf("Loi doc tep %s!\n",argv[2]);
        return 1;
    }
    int soluong1,soluong2;
    //char *x1=NULL,*x2=NULL;
    int i1=0,i2=0;
    char *line1 =NULL, *line2=NULL;
    fscanf(inp1, "%d",&soluong1);
    fscanf(inp2, "%d",&soluong2);
    cgetline(&line1,0,inp1);
    cgetline(&line2,0,inp2);
    product_t *list_product = malloc(soluong1*sizeof(product_t));
    order_t *list_order = malloc(soluong2*sizeof(order_t));
    while (cgetline(&line1, 0, inp1)){
        remove_tail_lf(line1);
        //if(line1 != x1){
        i1++;
        list_product[i1-1]= malloc(sizeof(struct product_s));
        list_product[i1-1]->name = strdup(strtok(line1," "));
        sscanf(strtok(NULL, " "),"%d",&list_product[i1-1]->price);
        //}
    }
    while (cgetline(&line2, 0, inp2)){
        remove_tail_lf(line2);
        //if(line2 != x2){
            i2++;
            list_order[i2-1]= malloc(sizeof(struct order_s));
            list_order[i2-1]->id = strdup(strtok(line2," "));
            sscanf(strtok(NULL," "),"%d",&list_order[i2-1]->k);
            int k = list_order[i2-1]->k;
            list_order[i2-1]->giatri = malloc(k*sizeof(giatri_t));
            for(int i=0;i<k;i++){
                list_order[i2-1]->giatri[i] = malloc(sizeof(struct giatri_s));
                list_order[i2-1]->giatri[i]->name = strdup(strtok(NULL," "));
                sscanf(strtok(NULL," "),"%d",&list_order[i2-1]->giatri[i]->number);
            }
        //}
    }
   //free(x1);
   //free(x2);
    free(line1);
    free(line2);
    fclose(inp1);
    fclose(inp2);
    
    printf("%d %d\n",soluong1, soluong2);
    /*output_t *list_ouput = malloc(soluong2*sizeof(output_t));

    for(int i=0;i<soluong2;i++){
        calculat_price(list_order[i],list_product,soluong1,list_ouput[i]);
        print_output(list_ouput[i]);
    }
    print_output_final(list_ouput,soluong2);*/
    return 0;
}