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

void selection_sort(std::vector<int>& array) {
    const size_t size = array.size();
    for (size_t i = 0; i + 1 < size; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(array[i], array[min_index]);
        }
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
    selection_sort(numbers);
    print_array(numbers);
    return 0;
}