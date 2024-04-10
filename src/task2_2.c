#include <stdio.h>
#include<math.h>

void real_to_bin(float num);

int main() {
    float num;
    scanf("%f", &num);
    real_to_bin(num);
    return 0;
}

void real_to_bin(float num){
    int binary[32] = {0};
    //sign bit
    if(num > 0){
        binary[0] = 0;
    }
    else{
        binary[0] = 1;
        num = -num;
    }
    //integer part and find e
    int int_part = (int)num;
    int e = 0;
    while(pow(2, e) < int_part){
        e ++;
    }
    e = e + 127 - 1;
    //assign e to the array
    int temp = e;
    for(int i = 1; i <= 8; i++){
        if(temp > pow(2, 8 - i)){
            binary[i] = 1;
            temp -= pow(2, 8 - i);
        }
        else{
            binary[i] = 0;
        }
    }
    //floating part
    float floating_part = (float)(num / pow(2, e - 127) - 1);
    for(int i = 9; i < 32; i++){
		floating_part *= 2 ;
		if(floating_part < 1){
			binary[i] = 0;
		}
		else {
			binary[i] = 1;
			floating_part -= 1 ;
		}
	}
    for(int i = 0; i < 32; i++){
        printf("%d", binary[i]);
    }
}