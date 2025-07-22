// URL:https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1?page=5&company=Amazon&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;
int transitionPoint(vector<int> &arr)
{
    // code here
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{

    return 0;
}