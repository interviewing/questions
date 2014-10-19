#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_string(char* front, char* back)
{
    while (front && back && front < back) {
        char tmp = *front;
        *front = *back;
        *back = tmp;
        ++front;
        --back;
    }
}

void reverse_words(char* front, char* back)
{
    char* a = front;
    char* b = front;
    while (a != NULL && b <= back) {
        while (!isspace(*b) && b <= back) ++b;
        --b; // go back one cos we would have gone too far
        reverse_string(a, b);
        a = b + 1;
        while (isspace(*a) && *a != '\0') ++a;
        b = a;
    }
}

int main(int argc, char** argv)
{
    char str[1024];
    str[0] = '\0';
    strcpy(str, "the world is so small");
    int front = 0;
    int back = strlen(str) - 1;
    printf("%s\n", str);
    reverse_string(&str[front], &str[back]);
    printf("%s\n", str);
    reverse_words(&str[front], &str[back]);
    printf("%s\n", str);

    return 0;
}
