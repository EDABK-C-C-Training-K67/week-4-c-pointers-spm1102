#include <stdio.h>

void int_to_bin(int num);

int main() {
    int num;
    scanf("%d", &num);
    int_to_bin(num);

    return 0;
}

void int_to_bin(int num) {
    // Size of integer in bits
    int size = sizeof(num) * 8;

    // Temporary array to store binary representation
    int binary[size];

    // Loop to convert decimal to binary
    for (int i = size - 1; i >= 0; i--) {
        binary[i] = num & 1;
        num >>= 1;
    }

    // Print binary representation
    for (int i = 0; i < size; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}


