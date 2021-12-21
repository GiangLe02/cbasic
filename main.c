#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "cgen.h"
#include "ext/io.h"
#include "all.h"

int main(int argc,char *argv[]){
    if(argc != 2){
        printf("Usage: '/prog songs.txt\n");
        return 1;
    }
    FILE *inp = fopen(argv[1],"r");
    if(!inp){
        printf("Loi doc tep %s!\n",argv[1]);
        return 1;
    }

    int c=0;
    char *line =NULL;
    song_t *list = malloc(c*sizeof(song_t));

    while(cgetline(&line, 0, inp)){
        c ++;
        list = (song_t*)realloc(list,c*sizeof(song_t));
        list[c-1] = malloc(sizeof(struct song_s));
        process(line,list[c-1]);
    }
    free (line);

    //switch case
    int choice1=0, choice2;
    int stt; //stt bai hat

    char str[1024], name[1024], singer[1024], writer[1024],year[1024];
    while(choice1!=5){
        menu();//print menu lên màn hình
        choice1 = menu_choice(); //nhập lựa chọn
        switch (choice1)
        {
        case 1://Lọc bài hát
            chon();//print menu phụ
            choice2 = menu_choice();
            sort(list,c,choice2);
            if(choice2>=1&& choice2<=4){
                heading(); print_songs(list,c);//print danh sach
            }
            break;
        case 2://tim kiem bai hat
            chon();
            choice2 = menu_choice();
            printf("Nhap tu khoa: ");
            clear_stdin(); fgets(str, 1024, stdin);
            remove_tail_lf(str);
            search(list,str,c,choice2);
            break;
        case 3:
            printf("Dien thong tin bai hat:\n");
            clear_stdin();

            printf("Nhap ten bai hat: ");
            fgets(name, 1024, stdin);
            remove_tail_lf(name);
            printf("Nhap ten ca si: ");
            fgets(singer, 1024, stdin);
            remove_tail_lf(singer);
            printf("Nhap ten nhac si: ");
            fgets(writer, 1024, stdin);
            remove_tail_lf(writer);
            printf("Nhap nam: ");
            fgets(year, 1024, stdin);
            remove_tail_lf(year);

            c++;
            list = (song_t*)realloc(list,c*sizeof(song_t));
            list[c-1] = malloc(sizeof(struct song_s));

            create_song(list[c-1],name,singer,writer,year,1);
            print_songs(list,c);
            save_song(list,c);
            break;
        case 4://xóa bài hát
            clear_stdin();
            printf("Nhap so thu tu bai hat ban muon xoa: ");
            scanf("%d",&stt); clear_stdin();
            int c3;
            printf("Ban thuc su muon xoa?\n1.Co\n2.Khong\n");
            print_song(list[stt-1]);
            do{
                printf("Lua chon cua ban: ");
                scanf("%d",&c3);
            } while(c3!=1 && c3 !=2);
            if(c3==1){
               list[stt-1]->base =0; 
                printf("Danh sach bai hat sau khi xoa:\n");

                heading(); print_songs(list,c);
                save_song(list,c);
            }
            break;
        default:
            break;
        }
    }
    fclose(inp);
    return 0;
}