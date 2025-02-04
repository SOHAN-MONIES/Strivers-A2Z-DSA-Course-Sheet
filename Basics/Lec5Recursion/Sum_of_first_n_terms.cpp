// URL: https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sumOfSeries(int n)
{
    if (n == 0)
        return 0;
    return pow(n, 3) + sumOfSeries(n - 1);
}

int main()
{
    cout << sumOfSeries(5);
    return 0;
}