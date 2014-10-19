#include <cstdio>
#include <iostream>

int find_combinations(int target, int current, int min, int max)
{
    int total_num = 0;
    for (int i = min; i <= max; ++i) {
        const int new_num = current + i;
        if (new_num == target) {
            ++total_num;
        }
        if (new_num >= target) {
            break;
        }
        total_num += find_combinations(target, new_num, min+1, max);
    }
    return total_num;
}

int main(int argc, char** argv)
{
    int min = 0;
    int max = 0;
    if (argc >= 3) {
        sscanf(argv[1], "%d", &min);
        sscanf(argv[2], "%d", &max);
    }
    std::cout << "min: " << min << "\n"
              << "max: " << max << "\n";
    const int total_num = find_combinations(100, 0, min, max);
    std::cout << "total_num: " << total_num << "\n";
}
