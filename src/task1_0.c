#include<stdio.h>

int main(){
    char arr[100];
    scanf("%[^\n]", arr);
    char *ptr = arr;
    int length = 0;
    while(*ptr != '\0'){
        length ++;
        ptr ++;
    }
    printf("%d",length);
    return 0;
}