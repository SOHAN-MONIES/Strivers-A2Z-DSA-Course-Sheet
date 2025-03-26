#include <iostream>
using namespace std;

int i = 1;
void printNos(int n)
{
    if (i > n)
        return;
    cout << i << " ";
    ++i;
    printNos(n);
}

int main()
{
    printNos(10);
}
