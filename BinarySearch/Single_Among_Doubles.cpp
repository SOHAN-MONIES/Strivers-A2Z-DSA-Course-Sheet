// URL: https://www.geeksforgeeks.org/problems/element-appearing-once2552/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    for(auto num:nums){
        int d1 = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), num)) - 1;
        int d2= distance(nums.begin(), lower_bound(nums.begin(), nums.end(), num)) ;
        if(d1-d2==0){
            return num;
        }
    }
    return -1;
}

int main()
{

    return 0;
}