// URL: https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printNos(int N)
{
    if (N == 0)
        return;
    cout << N << " ";
    N--;
    printNos(N);
}

int main()
{
    printNos(5);
    return 0;
}