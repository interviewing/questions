#include <iostream>
#include <cstdio>

int find_count(const int target, const int current, const int* numbers, const int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i) {
        const int value = numbers[i];
        const int new_current = current + value;
        if (new_current == target) {
            ++total;
        }
        if (new_current >= target) {
            break;
        }
        total += find_count(target, new_current, &numbers[i + 1], size - i - 1);
    }
    return total;
}

int find_count_iterative(const int target, const int current, const int min, const int max)
{
    int total = 0;
    for (int value = min; value <= max; ++value) {
        const int new_current = current + value;
        if (new_current == target) {
            ++total;
        }
        if (new_current >= target) {
            break;
        }
        total += find_count_iterative(target, new_current, value + 1, max);
    }
    return total;
}



int main()
{
    int target = 100;
    int min = 1;
    int max = 100;
    int* numbers = new int[max];
    for (int i = 0; i < max; ++i) {
        numbers[i] = i + min;
    }
    std::cout << find_count(target, 0, numbers, max) << "\n";
    std::cout << find_count_iterative(target, 0, min, max) << "\n";

    delete numbers;
    return 0;
}
