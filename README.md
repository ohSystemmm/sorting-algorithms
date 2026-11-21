# Sorting Algorithms

A collection of sorting algorithm implementations in C and C++. Each program generates 1,000 random integers and prints the sorted result to standard output.

## Overview

| Algorithm | C | C++ | Best | Average | Worst | Auxiliary space |
|---|---|---|---|---|---|---|
| Bubble sort | [bubble_sort.c](01_bubble_sort/bubble_sort.c) | [bubble_sort.cpp](01_bubble_sort/bubble_sort.cpp) | O(n) | O(n²) | O(n²) | O(1) |
| Selection sort | [selection_sort.c](02_selection_sort/selection_sort.c) | [selection_sort.cpp](02_selection_sort/selection_sort.cpp) | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion sort | [insertion_sort.c](03_insertion_sort/insertion_sort.c) | [insertion_sort.cpp](03_insertion_sort/insertion_sort.cpp) | O(n) | O(n²) | O(n²) | O(1) |
| Merge sort | [merge_sort.c](04_merge_sort/merge_sort.c) | [merge_sort.cpp](04_merge_sort/merge_sort.cpp) | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick sort | [quick_sort.c](05_quick_sort/quick_sort.c) | [quick_sort.cpp](05_quick_sort/quick_sort.cpp) | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Heap sort | [heap_sort.c](06_heap_sort/heap_sort.c) | [heap_sort.cpp](06_heap_sort/heap_sort.cpp) | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Radix sort | [radix_sort.c](07_radix_sort/radix_sort.c) | [radix_sort.cpp](07_radix_sort/radix_sort.cpp) | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) |