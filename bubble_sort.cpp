#include <cstdio>
#include <cstdlib>
#include <iostream>

void print(int* data, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("% 20d\n", data[i]);
    }
}

void bubble_sort(int* data, int size)
{
    bool swapped = true;
    int loops = 0;
    for (int i = 0; i < size - 1 && swapped; ++i) {
        swapped = false;
        for (int j = 0; j < size - 1; ++j) {
            if (data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                swapped = true;
            }
        }
        ++loops;
    }
    printf("bubble_sort: %d loops\n", loops);
}

int main(int argc, char** argv)
{
    int n = 0;
    int seed = time(0);
    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    if (argc > 2) {
        sscanf(argv[2], "%d", &seed);
    }
    srand(seed);
    int* data = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        int value = rand();
        data[i] = value;
    }
    print(data, n);
    std::cout << "--------------------------------------------------------------------------------\n";

    bubble_sort(data, n);
    print(data, n);

    free(data);

    return 0;
}
