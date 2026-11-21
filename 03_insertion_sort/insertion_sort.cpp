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

void insertion_sort(std::vector<int>& array) {
    const int size = static_cast<int>(array.size());
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
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
    insertion_sort(numbers);
    print_array(numbers);
    return 0;
}