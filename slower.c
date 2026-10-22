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
    unsigned int pow = power(a, b);
    unsigned int result = pow % c; // Im pretty sure this just like overflows so thats nice.
    printf("%d\n", result);
}