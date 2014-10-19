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

int print(int* data, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("% 20d\n", data[i]);
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

    boost::random::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    boost::random::mt19937 gen(get_seed());

    int* data = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        int value = dist(gen);
        data[i] = value;
    }
    print(data, n);



    free(data);

    return 0;
}
