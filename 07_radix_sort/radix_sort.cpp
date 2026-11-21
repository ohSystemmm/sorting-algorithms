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

int get_max(const std::vector<int>& array) {
    int max = array[0];
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void counting_sort(std::vector<int>& array, int exp) {
    const size_t size = array.size();
    std::vector<int> output(size);
    int count[10] = {0};

    for (size_t i = 0; i < size; ++i) {
        count[(array[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = static_cast<int>(size) - 1; i >= 0; --i) {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }
    for (size_t i = 0; i < size; ++i) {
        array[i] = output[i];
    }
}

void radix_sort(std::vector<int>& array) {
    if (array.empty()) {
        return;
    }
    int max = get_max(array);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(array, exp);
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
    radix_sort(numbers);
    print_array(numbers);
    return 0;
}