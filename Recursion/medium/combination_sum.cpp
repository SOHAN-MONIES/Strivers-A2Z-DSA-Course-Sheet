// URL:
#include <bits/stdc++.h>
using namespace std;

void findCombination(int i,vector<int> &arr,int target,vector<int> &temp, vector<vector<int>> &ans){
    if(i==arr.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }
    if(arr[i]<=target){
        temp.push_back(arr[i]);
        findCombination(i,arr,target-arr[i],temp,ans);
        temp.pop_back();
    }
    findCombination(i+1,arr,target,temp,ans);
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    findCombination(0,candidates,target,temp,ans);
    return ans;
}
int main() {
    return 0;
}
