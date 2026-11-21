#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000
#define MAX_VALUE 10000

void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE + 1);
    }
}

int get_max(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void counting_sort(int array[], int size, int exp) {
    int* output = (int*)malloc(size * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
    free(output);
}

void radix_sort(int array[], int size) {
    int max = get_max(array, size);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(array, size, exp);
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

int main() {
    int numbers[ARRAY_SIZE];
    srand(time(NULL));
    generate_random_array(numbers, ARRAY_SIZE);
    radix_sort(numbers, ARRAY_SIZE);
    print_array(numbers, ARRAY_SIZE);
    return 0;
}