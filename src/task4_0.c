#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_line_length 30

void allocate(char*** arr, int num_lines, int line_length);



int main(){
    int num_line = 1, line_length = max_line_length;
    char **arr = NULL;
    allocate(&arr, num_line, line_length);

    while(1){
        for(int i = 0; i < num_line; i++){
            fgets(arr[i], line_length + 1,stdin);
             if (arr[i][strlen(arr[i]) - 1] == '\n') {
                arr[i][strlen(arr[i]) - 1] = '\0';
            }
        }

        for(int i = 0; i < num_line; i++){
            printf("\n%s", arr[i]);
        }
        if (strcmp(arr[num_line - 1], "*") == 0) {
            break;
        }
        arr = (char**)realloc(arr, num_line * sizeof(char *));
        if(arr ==NULL){
            return 0;
        }
        for (int i = 0; i < num_line; i++) {
            arr[i] = (char*)realloc(arr[i], (line_length + 1) * sizeof(char*));
            if(arr[i] == NULL){
                return 0;
            }
        }
    }

    for(int i = 0; i < num_line; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}

void allocate(char*** arr, int num_lines, int line_length){
    *arr = (char**)calloc(num_lines, sizeof(char));
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


