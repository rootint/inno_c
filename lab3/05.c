#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(short n) {
    int res = 1;
    for (short i = 1; i <= n; i++) res *= i;
    return res;
} 

int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    for (long long i = a; i <= b; i++) {    
        long long sum = 0, num = i;
        while (num != 0) {
            sum += factorial(num % 10);
            num /= 10;
        }
        if (sum == i) {
            printf("%lld\n", i);
        }
    }
    return 0;
}