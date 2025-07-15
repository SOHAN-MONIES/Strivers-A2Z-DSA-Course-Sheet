// URL:- https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

    int largest(vector<int> &arr) {
        int large=arr[0];
        for(int i=1;i<arr.size();i++){
            if(large<arr[i]){
                large=arr[i];
            }
        }
        return large;
    }
int main()
{

    return 0;
}
