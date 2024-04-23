#include <stdio.h>

void floatToBinary(float num) {
  unsigned int* ptr = (unsigned int*)&num;
  unsigned int binary = *ptr;
  unsigned int mask = 1 << 31;
  for (int i = 0; i < 32; i++) {
      printf("%d", (binary & mask) ? 1 : 0);
      binary <<= 1;
      if ((i + 1) % 8 == 0);
    }

    printf("\n");
}

int main() {
  float num;
  scanf("%f", &num);
  floatToBinary(num);
  return 0;
}
