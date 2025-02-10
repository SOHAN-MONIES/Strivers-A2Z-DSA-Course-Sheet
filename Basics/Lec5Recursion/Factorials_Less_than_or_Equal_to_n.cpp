// URL: https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}
vector<long long> factorialNumbers(long long n)
{
    int i = 1;
    vector<long long> v1;
    while (fact(i) <= n)
    {
        v1.push_back(fact(i));
        i++;
    }
    return v1;
}

int main()
{
    cout << fact(32);
    return 0;
}