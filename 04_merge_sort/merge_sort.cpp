#include <iostream>
#include <vector>
#include <random>

constexpr int ARRAY_SIZE = 1000;
constexpr int MAX_VALUE = 10000;

void generate_random_array(std::vector<int>& array) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, MAX_VALUE);
    for (int& val : array) {
        val = dist(gen);
    }
}

void merge(std::vector<int>& array, int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    std::vector<int> left_array(left_size);
    std::vector<int> right_array(right_size);

    for (int i = 0; i < left_size; ++i) {
        left_array[i] = array[left + i];
    }
    for (int j = 0; j < right_size; ++j) {
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
}

void merge_sort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void print_array(const std::vector<int>& array) {
    for (int val : array) {
        std::cout << val << '\n';
    }
}

int main() {
    std::vector<int> numbers(ARRAY_SIZE);
    generate_random_array(numbers);
    merge_sort(numbers, 0, ARRAY_SIZE - 1);
    print_array(numbers);
    return 0;
}