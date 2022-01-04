#include "struct.c"
#define to_output(n) (*(output_t *)n)
void calculat_price(order_t n, product_t *m,int x,output_t nn){
    int price =0;
    for(int i=0; i<n->k; i++){
        for(int j=0;j<x;j++){
            if(strcmp(m[j]->name,n->giatri[i]->name)){
                price += m[j]->price * n->giatri[i]->number;
            }
        }   
    }
    add_output(nn,n->id,price);
}
int output_cmp_price(const void *v1,const void*v2){
    int price1 = to_output(v1)->price,
        price2 = to_output(v2)->price;
    return price1 - price2;
}
void print_output_final(output_t *n,int count){
    qsort(n,count,sizeof(output_t),output_cmp_price);
    for(int i=0;i<3;i++){
        print_output(n[i]);
    }
}