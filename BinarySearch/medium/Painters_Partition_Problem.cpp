// URL:https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
#include <bits/stdc++.h>
using namespace std;

int calTime(vector<int> &arr, int k,int m){
    int noOfPainter = 1;
    int calculatedtime = 0;
    for(auto num:arr){
        if(num+calculatedtime>m){
            noOfPainter++;
            calculatedtime = num;
        }
        else{
            calculatedtime += num;
        }
    }
    return noOfPainter;
}

    int minTime(vector<int> &arr, int k)
{
    if(k>arr.size()){
        return -1;
    }
    int l = *max_element(arr.begin(), arr.end());
    int h = accumulate(arr.begin(), arr.end(),0);
    while(l<=h){
        int m = (l + h) / 2;
        if(calTime(arr,k,m)<=k){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return l;
}
int main() {
    
    return 0;
}