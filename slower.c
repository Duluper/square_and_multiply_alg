#include <stdio.h>
#include <math.h>

int main() {
    unsigned int a = 3;
    unsigned int b = 75;
    unsigned int c = 100;
    unsigned int power = pow(a, b); // This overflows (in this case)
    unsigned int result = power % c;
    printf("%d\n", result);
}