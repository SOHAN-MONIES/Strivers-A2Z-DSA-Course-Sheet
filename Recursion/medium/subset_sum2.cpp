#include <bits/stdc++.h>
using namespace  std;
void findU(vector<vector<int>> &ans,vector<int> &arr,vector<int> &temp, int start){
    ans.push_back(temp);
    for(int i=start;i<arr.size();i++){
        if (i>start&&arr[i]==arr[i-1]){ continue;}
        temp.push_back(arr[i]);
        findU(ans,arr,temp,i+1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        findU(res,nums,temp,0);
        return res;
}

int main() {
    vector<int> arr={1,2,2};
    vector<vector<int>> res=subsetsWithDup(arr);
    for(int i=0;i<res.size();i++) {
        for(int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}