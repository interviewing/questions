#include <stdio.h>

int find_count(int target, int current, int* numbers, int num_size)
{
    int total_num = 0;
    for (int i = 0; i < num_size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    for (int i = 0; i < num_size; ++i) {
        int v = numbers[i];
        int new_num = current + v;
        if (new_num == target) {
            printf("found: %d\n", target);
            ++total_num;
        }
        if (new_num >= target) {
            printf("total: %d; break\n", new_num);
            printf("\n");
            break;
        }
        int new_num_size = num_size - i - 1;
        printf("i=%d v=%d find_count(%d, %d, &numbers[%d], %d)\n", i, v, target, new_num, i+1, new_num_size);
        total_num += find_count(target, new_num, &numbers[i+1], new_num_size);
    }
    return total_num;
}


#define MINIMUM 1
#define MAXIMUM 10
#define TARGET 10

int main(int argc, char** argv)
{
    int numbers[MAXIMUM];
    for (int i = 0; i < MAXIMUM; ++i) {
        numbers[i] = i + 1;
    }
    printf("find_count(%d, %d, &numbers[%d], %d)\n", TARGET, 0, 0, MAXIMUM);
    printf("%d\n", find_count(TARGET, 0, numbers, MAXIMUM));
}
