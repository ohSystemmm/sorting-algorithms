#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

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

int partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (array[j] <= pivot) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}

void quick_sort(std::vector<int>& array, int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);
        quick_sort(array, pivot_index + 1, high);
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
    quick_sort(numbers, 0, ARRAY_SIZE - 1);
    print_array(numbers);
    return 0;
}