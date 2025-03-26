// URL:https://www.geeksforgeeks.org/problems/print-gfg-n-times/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printGfg(int N)
{
    if (N == 0)
        return;
    cout << "GFG" << " ";
    N--;
    printGfg(N);
}

int main()
{
    printGfg(5);
    return 0;
}