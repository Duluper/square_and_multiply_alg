#include <stdio.h>

unsigned int power(int a, int b) { // a^b
    unsigned int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main() {
    unsigned int a = 512;
    unsigned int b = 10;
    unsigned int c = 100;
    unsigned int pow = power(2, 10);
    unsigned int result = pow % c;
    printf("%d\n", result);
}