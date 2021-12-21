#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 typedef struct song_s{
    int base;
    char *name;
    char *singer;
    char *writer;
    char *year;
} *song_t;

//lưu bài hát
void create_song(song_t n,char *name,char *singer,
 char *writer, char *year, int m){
     n -> name = strdup(name);
     n -> singer = strdup(singer);
     n -> writer = strdup(writer);
     n -> year = strdup(year);
     n -> base = m;
 }

//in 1 bài hát
 void print_song(song_t n){
     printf("%10s %10s %10s %10s \n", n->name, n ->singer
     ,n->writer, n->year);
 }

//lưu 1 bài hát với các thông tin cách nhau bởi dấu "*#*"
 void process(char *line, song_t n){
     char *name, *singer,*writer,*year;
     remove_tail_lf(line);
     const char s[4]="*#*";
     name = strtok(line,s);
     singer = strtok(NULL,s);
     writer = strtok(NULL, s);
     year = strtok(NULL, s);
     create_song(n,name,singer,writer, year,1);
 }

//in dãy bài hát
 void print_songs(song_t *nn, int count){
     int i= 0;
     printf("\n");
     for(int i =0; i<count;i++){
         if(nn[i]->base){
             printf("%d   ",i+1);
             print_song(nn[i]);
         }
     }
     printf("\n");
 }

//lưu bài hát mới vào lại file
 void save_song(song_t *nn, int count){
     FILE *out = fopen("songs.txt","w");
     for(int i=0;i<count;i++){
         if(nn[i]->base){
             if(i){fprintf(out,"\n");}
             fprintf(out,"%s*#*",nn[i]->name);
             fprintf(out,"%s*#*",nn[i]->singer);
             fprintf(out,"%s*#*",nn[i]->writer);
             fprintf(out,"%s*#*",nn[i]->year);
         }
     }
     fclose(out);
 }