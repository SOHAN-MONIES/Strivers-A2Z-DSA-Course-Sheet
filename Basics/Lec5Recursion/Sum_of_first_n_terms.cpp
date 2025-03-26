// URL: https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sumOfSeries(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sumOfSeries(i - 1, sum + i);
}

int sumOfSeries(int n)
{

    if (n == 0)
    {
        return 0;
    }
    return pow(n, 3) + sumOfSeries(n - 1);
}

int main()
{
    cout<<sumOfSeries(5);
    return 0;
}