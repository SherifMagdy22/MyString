#include "MyString.h"

void *my_memchr(const void *str, int c, size_t n){
    if(str == NULL || n==0){
        return NULL;
    }

    size_t i=0;
    while((i<n) && (*((unsigned char*)str+i) != '\0') && (*((unsigned char*)str+i) != EOF)){
        if(*((unsigned char*)str+i) == c){
            return ((unsigned char*)str+i);
        }
        i++;
    }
    return NULL;
}

int my_memcmp(const void *str1, const void *str2, size_t n){
    unsigned int cmp1 = 0, cmp2 = 0;

    for(size_t i=0; i<n; i++){
        cmp1 += *((unsigned char*)str1+i);
        cmp2 += *((unsigned char*)str2+i);
    }

    return cmp1-cmp2;
}

void *my_memcpy(void *dest, const void * src, size_t n){
    for(size_t i=0; i<n; i++){
        *((unsigned char*)dest+i) = *((unsigned char*)src+i);
    }
    return dest;
}

void *my_memset(void *str, int c, size_t n){
    for(size_t i=0; i<n; i++){
        *((unsigned char*)str+i) = c;
    }
    return str;
}

char *my_strcat(char *dest, const char *src){
    size_t i=0, j=0;
    while(*(dest + i) != '\0'){
        i++;
    }

    while(*((unsigned char*)src + j) != '\0'){
        *(dest + i + j) = *(src + j); 
        j++;
    }

    return dest;
}

char *my_strcpy(char *dest, const char *src){
    if(dest==NULL || src==NULL){
        return NULL;
    }

    size_t i = 0;
    while(*(src+i) != '\0'){
        *(dest+i) = *(src+i);
        i++;
    }
    
    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n){
    if(dest==NULL || src==NULL){
        return NULL;
    }

    size_t i=0, j=0;
    while(*(dest + i) != '\0'){
        i++;
    }

    for (j=0; j < n; j++)
    {   
        *(dest+i+j) = *(src+j);
        if(*(src+j)=='\0') break;
    }

    return dest;
}

char *my_strchr(const char *str, int c){
    unsigned int i=0;
    while(*(str+i)!='\0'){
        if(*(str+i) == c) return (char*)(str+i);
        i++;
    }
    return NULL;
}

int my_strcmp(const char *str1, const char *str2){
    unsigned int cmp1 = 0, cmp2 = 0, i = 0;

    while( (*(str1+i)!='\0') || (*(str2+i)!='\0') ){
        cmp1 += *(str1+i);
        cmp2 += *(str2+i);
        i++;
    }

    return cmp1-cmp2;
}

int my_strncmp(const char *str1, const char *str2, size_t n){
    return my_memcmp(str1, str2, n);
}

char *my_strncpy(char *dest, const char *src, size_t n){
    return (char*) my_memcpy(dest, src, n);
}

size_t strcspn(const char *str1, const char *str2){
    size_t i=0, j=0;
    while(*(str1+i)!='\0'){
        while(*(str2+j)!='\0'){
            if( *(str1+i)==*(str2+j) ) return i;
            j++;
        }
        j=0;
        i++;
    }

    return(i+1);
}

size_t my_strlen(const char *str){
    size_t count = 0;
    while (*(str+count)!='\0'){
        count++;
    }
    return count-1;
}

char *my_strpbrk(const char *str1, const char *str2){
    char *ptr = (char*)str1;
    size_t i=0, j=0;
    while(*(str1+i)!='\0'){
        while(*(str2+j)!='\0'){
            if( *(str1+i)==*(str2+j) ) return (char*)(str1+i);
            j++;
        }
        j=0;
        i++;
    }
    return NULL;
}

char *my_strrchr(const char *str, int c){
    char *lastPtr = NULL;
    size_t i = 0;

    while(*(str+i) != '\0'){
        if(*(str+i) == c) lastPtr = (char*) str + i;
        i++;
    }
    return lastPtr;
}

size_t my_strspn(const char *str1, const char *str2){
    size_t i = 0;

    while( (*(str1+i) != '\0') || (*(str2+i) != '\0') ){
        if( *(str1+i) != *(str2+i) ) return i;
        i++;
    }
    return i;
}

char *my_strstr(const char *haystack, const char *needle){
    size_t i = 0, j = 0;

    while( *(haystack+i) != '\0'){
        if( *(haystack+i) == *(needle+j) ) j++;
        else j=0;
        if( *(needle+j) == '\0' ) return (haystack+i-j+1);
        i++;
    }
    return (char*)NULL;
}