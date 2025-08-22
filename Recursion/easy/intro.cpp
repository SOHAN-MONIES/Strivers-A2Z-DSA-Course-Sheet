// URL:
#include <bits/stdc++.h>
using namespace std;

void printMsg(int n)
{
    if (n == 0)
        return;
    cout << n << "  ";
    printMsg(--n);
}

int main()
{

    printMsg(5);
    return 0;
}