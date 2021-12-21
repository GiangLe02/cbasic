#include "struct.c"
#define to_song(n) (*(song_t*)n)
/*sắp xếp chuỗi bài hát theo tên, ca sĩ, nhạc sĩ, năm sáng tác*/
int song_cmp_name(const void *v1, const void *v2){
    return strcmp(to_song(v1)->name, to_song(v2)->name);
}
int song_cmp_singer(const void *v1, const void *v2){
    return strcmp(to_song(v1)->singer, to_song(v2)->singer);
}
int song_cmp_writer(const void *v1, const void *v2){
    return strcmp(to_song(v1)->writer, to_song(v2)->writer);
}
int song_cmp_year(const void *v1, const void *v2){
    int t1,t2;
    sscanf(to_song(v1)->year, "%d",&t1);
    sscanf(to_song(v2)->year,"%d",&t2);
    return t1-t2;
}

void sort(song_t *n, int count, int x){
    switch (x)
    {
    case 1:
        qsort(n,count,sizeof(song_t), song_cmp_name);
        break;
    
    case 2:
        qsort(n,count,sizeof(song_t),song_cmp_singer);
        break;
    case 3:
        qsort(n,count,sizeof(song_t),song_cmp_writer);
        break;
    case 4:
        qsort(n,count,sizeof(song_t),song_cmp_year);
        break;
    default:
        break;
    }
}