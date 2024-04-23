#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_length 30

int main() {
    char** arr = NULL;
    int row = 1, col = max_length, i;

    arr = (char**)malloc(row * sizeof(char*));
    if (arr == NULL) {
        return 1;
    }
    for (i = 0; i < row; i++) {
        arr[i] = (char*)malloc((col + 1) * sizeof(char*));
        if (arr[i] == NULL) {
            return 1;
        }
    }
    while (1) {
        for (i = 0; i < row; i++) {
            fgets(arr[i], col + 1, stdin); 
            if (arr[i][strlen(arr[i]) - 1] == '\n') {
                arr[i][strlen(arr[i]) - 1] = '\0';
            }
        }
        for (i = 0; i < row; i++) {
            printf("%s\n", arr[i]);
        }
        if (strcmp(arr[row - 1], "*") == 0) { 
            break;
        }
        
        arr = (char**)realloc(arr, row * sizeof(char *));
        for (i = 0; i < row; i++) {
            arr[i] = (char*)realloc(arr[i], (col + 1) * sizeof(char*));
        }
    }
    for (i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
