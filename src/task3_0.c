#include<stdio.h>
#include<stdlib.h>

#define max_length 30
int main(){
    char **arr = NULL;
    int row = 10, col = max_length;

    arr = (char **)calloc(row, sizeof(char));
    if(arr == NULL){
        return 1;
    }
    for(int i = 0; i < row; i++){
        arr[i] = (char*)calloc(col + 1, sizeof(char));
        if(arr[i] == NULL){
            return 1;
        }
    }
    
    for(int i = 0; i < row; i++){
        scanf("%s", arr[i]);
    }
    
    for(int i = 0; i < row; i++){
        printf("\n%s", arr[i]);
    }

    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}