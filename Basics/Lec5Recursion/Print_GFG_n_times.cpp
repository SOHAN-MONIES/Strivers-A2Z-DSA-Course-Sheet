// URL:https://www.geeksforgeeks.org/problems/print-gfg-n-times/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int i = 1;
void printGfg(int N)
{
    if (i > N)
        return;
    cout << "GFG ";
    i++;
    printGfg(N);
}

int main()
{
    printGfg(5);
    return 0;
}