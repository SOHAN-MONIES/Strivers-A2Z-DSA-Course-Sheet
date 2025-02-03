// URL:- https://takeuforward.org/data-structure/count-digits-in-a-number/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void Count(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        int l = n % 10;
        cnt++;
        n = n / 10;
    }
    cout << cnt << endl;
}

int main()
{
    Count(123);

    return 0;
}