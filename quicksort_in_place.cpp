#include <cstdio>
#include <cstdlib>
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

void print(int* data, int left, int right)
{
    for (int i = left; i <= right; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int partition(int* data, int left, int right, int pivot_index)
{
    int pivot_value = data[pivot_index];
    // move pivot out of the way to the end of the data array so
    // that we can operate on the rest of the elements in a contiguous manner.
    swap(&data[pivot_index], &data[right]);
    // store_index is the key to reusing the input data array.  it is used to
    // remember where the next write location should be as we iterate through
    // the input.
    int store_index = left;
    // iterate through 0 to n-1, leaving the location where the pivot is
    // saved alone, reusing the input data array itself to swap values smaller
    // than the pivot value to the left side of the array, using store_index to
    // remember where the next element should be swapped into.
    for (int i = left; i < right; ++i) {
        if (data[i] < pivot_value) {
            swap(&data[i], &data[store_index]);
            ++store_index;
        }
    }
    // move the pivot value from its saved location at the end of the array
    // to its rightful place.  note that the pivot will now be in its final
    // location after sorting.
    swap(&data[store_index], &data[right]);
    return store_index;
}

void quicksort(int* data, int left, int right)
{
    // left == right is the exit condition of this recursive function.
    if (left < right) {
        // use the left-most element as the pivot since data elements are completely random.
        int pivot_index = left;
        printf("pre: %d: ", pivot_index);
        print(data, left, right);
        // reorganize data elements so that every element smaller than pivot is to its
        // left and every element bigger is to its right, returning the new position of pivot
        // so that it can be used to determine the boundaries of the next quicksort calls.
        // note that element chosen as pivot is already in the correct position after the
        // partition() call.
        int pivot_new_index = partition(data, left, right, pivot_index);
        printf("post: %d: ", pivot_new_index);
        print(data, left, right);
        printf("\n");
        // sort the left half
        quicksort(data, left, pivot_new_index - 1);
        // sort the right half
        quicksort(data, pivot_new_index + 1, right);
    }
}

int main(int argc, char** argv)
{
    int n = 0;
    int seed = get_seed();
    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    if (argc > 2) {
        sscanf(argv[2], "%d", &seed);
    }

    //boost::random::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    boost::random::uniform_int_distribution<> dist(0, 10000);
    boost::random::mt19937 gen(get_seed());

    int* data = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        int value = dist(gen);
        data[i] = value;
    }
    print(data, n);
    quicksort(data, 0, n - 1);
    print(data, n);

    free(data);

    return 0;
}
