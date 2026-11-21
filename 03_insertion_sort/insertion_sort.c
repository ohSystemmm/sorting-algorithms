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

void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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
    insertion_sort(numbers, ARRAY_SIZE);
    print_array(numbers, ARRAY_SIZE);
    return 0;
}