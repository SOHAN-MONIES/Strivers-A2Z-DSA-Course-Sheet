// URL:
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    int m=1<<n;
    vector<vector<int>> ans(m);
    for (int i=0;i<m;i++) {
        vector<int> temp;
        for (int j=0;j<n;j++) {
            if (i&&(1<<j)) {
                temp.push_back(nums[i]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
