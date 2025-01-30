// URL:-  same problem but without sort function
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int SecondSmallest(vector<int> arr)
{
    int smallest = INT_MAX;
    int SecondSmallest = INT_MAX;
    for (auto num : arr)
    {
        smallest = min(smallest, num);
    }
    for (auto num : arr)
    {
        if (num > smallest && num < SecondSmallest)
            SecondSmallest = num;
    }
    return SecondSmallest;
}

int main()
{

    return 0;
}