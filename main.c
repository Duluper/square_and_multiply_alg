#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a^b mod c

unsigned int read_bit(int a, int pos) {
    unsigned int result = (a >> pos) & 1; 
    return result;
}

unsigned int count_bits_magnitude(unsigned int n) {
    if (n == 0) return 1;
    unsigned int count = 0;
    while (n > 0) {
        count++;
        n >>= 1; // right shift by 1
    }
    return count;
}

int main() {
    unsigned int a = 3;
    unsigned int b = 75;
    unsigned int c = 100;
    
    unsigned int b_bits = count_bits_magnitude(b);
    unsigned int arr_size = 0;
    unsigned int *base10_base2 = (unsigned int*)calloc(arr_size, sizeof(int)); // I have no idea what to call this
    unsigned int base10_base2_index = 0;
    if (base10_base2 == NULL) {
        printf("Could not allocate memory.\n");
        exit(1);
    }
    for (int i = 0; i < b_bits; i++) {
        unsigned int current_bit = read_bit(b, i);
        if (current_bit != 0) {
            unsigned int base2 = pow(2, i);
            base10_base2[base10_base2_index] = base2;
            base10_base2_index++;
            unsigned int new_size = base10_base2_index;
            unsigned int *temp = realloc(base10_base2, new_size * sizeof(unsigned int));

            if (temp == NULL) {
                printf("Memory Re-allocation failed.\n");
                free(base10_base2);
                exit(1);
            }

            base10_base2 = temp;
            arr_size = new_size;
        }
    }
    unsigned int stop = base10_base2[arr_size - 1];

    unsigned int exponent = 2;
    unsigned int result = (a * a) % c;
    while (exponent != stop) {
        unsigned int temp_power = result * result;
        result = temp_power % c;
        exponent *= 2;
    }
    for (int i = 0; i < arr_size - 1; i++) {
        unsigned int current_val = base10_base2[i];
        unsigned int power = pow(a, current_val);
        result *= power;
    }
    result %= c;
    printf("Result: %d\n", result);
    
    free(base10_base2);
    return 0;
}