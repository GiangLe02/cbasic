#include<stdio.h>

void menu(){
    printf("1. Xem danh sach bai hat\n");
    printf("2. Loc danh sach bai hat\n");
    printf("3. Them bai hat\n");
    printf("4. Xoa bai hat\n");
    printf("5. Thoat\n");
}

int menu_choice(){
    int choice;
    printf("\nLua chon cua ban la [1,2,3,4,5]?");
    scanf("%d",&choice);
    if(choice>0||choice<6) return choice;
    else return menu_choice();
}

void chon(){
    printf("1. Ten bai hat\n");
    printf("2. Ca sy\n");
    printf("3. Nhac sy\n");
    printf("4. Nam sang tac\n");
    printf("5. Thoat\n");
}

void heading(){
    printf("%-10s%10s%10s%10s%10s","STT","Ten bai hat","Ca si","Nhac si","Nam");
}