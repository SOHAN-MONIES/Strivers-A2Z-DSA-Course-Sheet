// URL:-https://leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

  void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> numsDuplicate(n-k);
        for(int i=0;i<n-k;i++){
            numsDuplicate[i]=nums[i];
        }
        int j=0;
        for(int i=n-k;i<n;i++){
            nums[j]=nums[i];
            j++;
        }
        int i=0;
        for(int k=j;k<n;k++){
            nums[k]=numsDuplicate[i];
            i++;
        }
    }


void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> v3 = {1, 2, 3, 4, 5};
    rotateArr(v3, 2);
    for (auto num : v3)
    {
        cout << num << " ";
    }
    return 0;
}
