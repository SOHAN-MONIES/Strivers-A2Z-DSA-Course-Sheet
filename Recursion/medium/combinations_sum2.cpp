#include<iostream>
using namespace  std;


void findU(vector<vector<int>> &ans,vector<int> &arr,vector<int> &temp,int target,int start){
    if(target==0){
        ans.push_back(temp);
        return ;
    }
    for(int i=start;i<arr.size();i++){
        if(i>start&&arr[i-1]==arr[i]) continue;
        if(arr[i]>target) break;
        temp.push_back(arr[i]);
        findU(ans,arr,temp,target-arr[i],i+1);
        temp.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    findU(ans,candidates,temp,target,0);
    return ans;
}