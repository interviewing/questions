//http://www.youtube.com/watch?v=NdF1QDTRkck

#include <iostream>
#include <string>

using namespace std;

void RecSubsets(string soFar, string rest)
{
    if (rest == "") {
        cout << soFar << "\n";
    } else {
        // add to subset, remove from rest, recur
        RecSubsets(soFar + rest[0], rest.substr(1));
        // don't add to subset, remove from rest, recur
        RecSubsets(soFar, rest.substr(1));
    }
}

void ListSubset(string s)
{
    RecSubsets("", s);
}

int main(int argc, char** argv)
{
    if (argc > 1) {
        ListSubset(argv[1]);
    }
    return 0;
}
