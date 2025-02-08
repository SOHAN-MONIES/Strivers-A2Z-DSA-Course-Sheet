// URL:-https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=who-will-win
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int searchInSorted(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> v3 = {1, 2, 3, 4, 5};
    cout << searchInSorted(v3, 5);
    return 0;
}