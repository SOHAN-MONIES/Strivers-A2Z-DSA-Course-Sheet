// URL:
#include <bits/stdc++.h>
using namespace std;

void findPerms(vector<vector<int>> &ans,vector<int> &temp,vector<int> &mpp,vector<int> &arr) {
    if (temp.size()==arr.size()) {
        ans.push_back(temp);
        return;
    }


    for (int i=0;i<arr.size();i++) {

         if (i>0&&arr[i]==arr[i-1]&&!mpp[i-1]) continue;
        if (!mpp[i]){
            temp.push_back(arr[i]);
            mpp[i]=1;
            findPerms(ans,temp,mpp,arr);
            mpp[i]=0;
            temp.pop_back();
        }
    }
}


vector<vector<int>> uniquePerms(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> mpp(nums.size(),0);
    findPerms(ans,temp,mpp,nums);
    return ans;

}

int main() {
    vector<int> arr={1,1,3};
    vector<vector<int>> ans=uniquePerms(arr);
    for (auto row:ans) {
        for (auto ele:row) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
