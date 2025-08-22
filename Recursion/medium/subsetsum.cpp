#include<bits/stdc++.h>
using namespace std;

void findSubSet(int i,vector<int> &arr,vector<int> &temp,vector<int> &res) {
    if (i==arr.size()) {
        int sum=0;
        for (auto ele:temp) {
            sum+=ele;
        }
        res.push_back(sum);
        return;
    }
    temp.push_back(arr[i]);
    findSubSet(i+1,arr,temp,res);
    temp.pop_back();
    findSubSet(i+1,arr,temp,res);
}


vector<int> subsetSums(vector<int>& arr) {
    // code here
    vector<int> res;
    vector<int> temp;
    findSubSet(0, arr, temp,res);
    return res;

}


int main() {
    vector<int> arr = {2,3};
    vector<int> ans = subsetSums(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}