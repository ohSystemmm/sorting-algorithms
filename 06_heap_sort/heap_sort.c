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

void heapify(int array[], int size, int root) {
    int largest = root;
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;
    if (left_child < size && array[left_child] > array[largest]) {
        largest = left_child;
    }
    if (right_child < size && array[right_child] > array[largest]) {
        largest = right_child;
    }
    if (largest != root) {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void heap_sort(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
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
    heap_sort(numbers, ARRAY_SIZE);
    print_array(numbers, ARRAY_SIZE);
    return 0;
}