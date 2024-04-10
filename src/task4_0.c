#include<stdio.h>
#include<stdlib.h>

#define max_line_length 30

void allocate(char ***arr, int num_lines, int line_length);

int main(){
    int num_line = 10, line_length = max_line_length;
    char **arr = NULL;
    allocate(&arr, num_line, line_length);

    for(int i = 0; i < num_line; i++){
        scanf("%s", arr[i]);
    }

    for(int i = 0; i < num_line; i++){
        printf("\n %s", arr[i]);
    }

    for(int i = 0; i < num_line; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}

void allocate(char ***arr, int num_lines, int line_length){
    *arr = (char **)calloc(num_lines, sizeof(char));
    if(*arr == NULL){
        exit(1);
    }
    for(int i = 0; i < num_lines; i++){
        (*arr)[i] = (char*)calloc(line_length + 1, sizeof(char));
        if((*arr)[i] == NULL){
            exit(1);
        }
    }
}