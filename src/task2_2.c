#include <stdio.h>
#include <math.h>

void reverse(int arr[], int left, int right);

void real_to_bin(float num);


int main() {
	float num;
    scanf("%f", &num);
    real_to_bin(num);

    return 0;
}

void reverse(int arr[], int left, int right){
    int temp, i;
    for(i = 0; i < (int)((right -left) / 2 + 1); i++){
        temp = arr[left + i];
        arr[left + i] = arr[right -i];
        arr[right - i] = temp;
    } 
}

void real_to_bin(float num){
    int binary[32] = {0};
    // Sign bit
    if(num > 0) {
        binary[0] = 0;
    }
    else if(num == 0){
    	int j;
    	for(j = 0; j < 32; j++){
    		printf("%d", binary[j]);
		}
		return;
	}
    else {
        binary[0] = 1;
        num = -num;
    }
	
    int int_part = (int)num, i = 1; 
    float floating_part = num - (float)int_part;
    int *ptr = binary;
    ptr = ptr + 8;
    while(int_part > 0){
        *(ptr + i++) = int_part % 2;
        int_part /= 2;
    }
    int cnt = i;
    reverse(binary, 8, 8 + i - 1 );

    while(floating_part > 0){
        floating_part *= 2;
        if(floating_part < 1){
            *(ptr + i++ - 1) = 0;
        }
        else{
            *(ptr + i++ -1) = 1;
            floating_part -= 1;
        }
    }

    
    int e = 127 + cnt - 2;
    i = 1;
    while(e > 0){
        binary[i++] = e % 2;
        e /= 2;
    }
    reverse(binary, 1, 8);
    
    for(i = 0; i < 32; i++){
        printf("%d", binary[i]);
    }
}