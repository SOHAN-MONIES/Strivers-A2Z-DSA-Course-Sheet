// URL: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int i = 1;
void printNos(int n)
{

    if (i > n)
        return;
    cout << i << " ";
    i++;
    printNos(i);
}
int main()
{
    printNos(5);
}