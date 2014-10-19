//http://www.youtube.com/watch?v=NdF1QDTRkck

#include <iostream>
#include <string>

using namespace std;

void RecPermute(string soFar, string rest)
{
    if (rest == "") {
        cout << soFar << "\n";
    } else {
        for (size_t i = 0; i < rest.length(); ++i) {
            string next = soFar + rest[i];
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining);
        }
    }
}

void ListPermutations(string s)
{
    RecPermute("", s);
}

int main(int argc, char** argv)
{
    if (argc > 1) {
        ListPermutations(argv[1]);
    }

    return 0;
}
