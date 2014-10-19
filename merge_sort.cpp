#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

int get_seed()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return static_cast<int>(ts.tv_sec + ts.tv_nsec);
}

void print(int* data, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("% 20d\n", data[i]);
    }
    printf("--------------------------------------------------------------------------------\n");
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge_sort(int* data, int size, int* result)
{
    // base case where a single element is considered sorted
    if (size == 1) {
        memcpy(result, data, size*sizeof(int));
        return;
    }

    int divide_index = static_cast<int>(size / 2);

    int* left = data;
    int left_size = divide_index;
    int* left_result = result;
    merge_sort(left, left_size, left_result);
    printf("left\n");
    print(left, left_size);

    int* right = &data[divide_index];
    int right_size = size - divide_index;
    int* right_result = &result[divide_index];
    merge_sort(right, right_size, right_result);
    printf("right\n");
    print(right, right_size);

    int result_it = 0;
    for (int i = 0, j = 0; i < left_size || j < right_size; ) {
        int left_remainder = left_size - i;
        int right_remainder = right_size - j;
        if (left_remainder > 0 && right_remainder > 0) {
            if (left[i] <= right[j]) {
                result[result_it++] = left[i++];
            } else {
                result[result_it++] = right[j++];
            }
        } else if (left_remainder > 0) {
            result[result_it++] = left[i++];
        } else if (right_remainder > 0) {
            result[result_it++] = right[j++];
        } else {
            // NOP
        }
    }
    printf("result:\n");
    print(result, sizeof(result)/sizeof(int));
}

int main(int argc, char** argv)
{
    int n = 5;
    int seed = get_seed();
    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    if (argc > 2) {
        sscanf(argv[2], "%d", &seed);
    }
    int fixture[] = {
        9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    //boost::random::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    boost::random::uniform_int_distribution<> dist(0, 10000);
    boost::random::mt19937 gen(get_seed());

    int* data = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        int value = fixture[i]; //dist(gen);
        data[i] = value;
    }
    print(data, n);
    merge_sort(data, n, result);
    print(result, n);

    free(data);
    free(result);

    return 0;
}
