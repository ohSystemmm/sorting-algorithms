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

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);
        quick_sort(array, pivot_index + 1, high);
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
    quick_sort(numbers, 0, ARRAY_SIZE - 1);
    print_array(numbers, ARRAY_SIZE);
    return 0;
}