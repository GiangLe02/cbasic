#include<ctype.h>
#include "sapxep.c"

char *lower_letter(char *s){
    char *tmp = s;
    for(;*tmp;tmp++){
        *tmp = tolower((unsigned char)*tmp);
    }
    return s;
}
//tra bài hát theo tên
void search_name(song_t *n, char *p, int count){
    song_t *find = calloc(count,sizeof(song_t));
    int fo =0,i;
    char *tmp;
    for(i=0;i<count;i++){
        tmp = strdup(n[i]->name);
        if(strstr(lower_letter(tmp),lower_letter(p))){
            find[fo] = n[i];
            fo++;
        }
    }
    print_songs(find,fo);
}

//tra bài hát theo ca sĩ
void search_singer(song_t *n, char *p, int count){
    song_t *find = calloc(count, sizeof(song_t));
    int fo=0,i;
    char *tmp;
    for(i=0;i<count;i++){
        tmp = strdup(n[i]->singer);
        if(strstr(lower_letter(tmp),lower_letter(p))){
            find[fo]=n[i];
            fo++;
        }
    }
    print_songs(find,fo);
}

//tra bài hát theo nhạc sĩ
void search_writer(song_t *n, char *p, int count){
    song_t *find = calloc(count, sizeof(song_t));
    int fo=0,i;
    char *tmp;
    for(i=0;i<count;i++){
        tmp = strdup(n[i]->writer);
        if(strstr(lower_letter(tmp),lower_letter(p))){
            find[fo]=n[i];
            fo++;
        }
    }
    print_songs(find,fo);
}

//tra bài hát theo năm
void search_year(song_t *n, char *p, int count){
    song_t *find = calloc(count, sizeof(song_t));
    int fo=0,i;
    char *tmp;
    for(i=0;i<count;i++){
        tmp = strdup(n[i]->year);
        if(strstr(lower_letter(tmp),lower_letter(p))){
            find[fo]=n[i];
            fo++;
        }
    }
    print_songs(find,fo);
}

void search(song_t *n, char *p, int count, int x){
    switch(x){
        case 1:
            search_name(n,p,count);
            break;
        case 2:
            search_singer(n,p,count);
            break;
        case 3:
            search_writer(n,p,count);
            break;
        case 4:
            search_year(n,p,count);
            break;
        default: break;
    }
}