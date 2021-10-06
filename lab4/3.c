#include <stdio.h>
#define ULL_SIZE sizeof(unsigned long long)

typedef union {
    unsigned long long num;
    unsigned char bytes[ULL_SIZE];
} data;

void swap(unsigned char* a, unsigned char* b) {
    unsigned char c;
    c = *a;
    *a = *b;
    *b = c;
}

void encryption(unsigned char bytes[]) {
    for (char i = ULL_SIZE - 1; i >= 0; i -= 2) {
        swap(&bytes[i], &bytes[i - 1]);
    }
}

int main() {
    data un;
    scanf("%llu", &un.num);
    encryption(un.bytes);
    printf("%llu\n", un.num);
    encryption(un.bytes);
    printf("%llu\n", un.num);
    return 0;
}