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

void merge(int array[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int* left_array = (int*)malloc(left_size * sizeof(int));
    int* right_array = (int*)malloc(right_size * sizeof(int));

    for (int i = 0; i < left_size; i++) {
        left_array[i] = array[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_array[j] = array[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;

    while (i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            array[k++] = left_array[i++];
        } else {
            array[k++] = right_array[j++];
        }
    }

    while (i < left_size) {
        array[k++] = left_array[i++];
    }

    while (j < right_size) {
        array[k++] = right_array[j++];
    }

    free(left_array);
    free(right_array);
}

void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
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
    merge_sort(numbers, 0, ARRAY_SIZE - 1);
    print_array(numbers, ARRAY_SIZE);
    return 0;
}