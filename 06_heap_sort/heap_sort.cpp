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

void heapify(std::vector<int>& array, int size, int root) {
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
        std::swap(array[root], array[largest]);
        heapify(array, size, largest);
    }
}

void heap_sort(std::vector<int>& array) {
    int size = static_cast<int>(array.size());
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i);
    }
    for (int i = size - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
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
    heap_sort(numbers);
    print_array(numbers);
    return 0;
}