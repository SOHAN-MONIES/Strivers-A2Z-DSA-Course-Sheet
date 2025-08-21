#include <bits/stdc++.h>
using namespace std;

// Start: i=0, subset=[]
// ├── Exclude 1: i=1, subset=[]
// │   ├── Exclude 2: i=2, subset=[]
// │   │   ├── Exclude 3: i=3, subset=[]          → add []
// │   │   └── Include 3: i=3, subset=[3]       → add [3]
// │   └── Include 2: i=2, subset=[2]
// │       ├── Exclude 3: i=3, subset=[2]       → add [2]
// │       └── Include 3: i=3, subset=[2,3]     → add [2,3]
// └── Include 1: i=1, subset=[1]
//     ├── Exclude 2: i=2, subset=[1]
//     │   ├── Exclude 3: i=3, subset=[1]       → add [1]
//     │   └── Include 3: i=3, subset=[1,3]     → add [1,3]
//     └── Include 2: i=2, subset=[1,2]
//         ├── Exclude 3: i=3, subset=[1,2]     → add [1,2]
//         └── Include 3: i=3, subset=[1,2,3]   → add [1,2,3]

void generate(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& ans) {
    if (i == nums.size()) {        // Base condition: all elements processed
        ans.push_back(subset);     // Add current subset
        return;
    }

    // Choice 1: Exclude nums[i]
    generate(nums, i + 1, subset, ans);

    // Choice 2: Include nums[i]
    subset.push_back(nums[i]);
    generate(nums, i + 1, subset, ans);
    subset.pop_back();             // Backtrack
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subset;
    generate(nums, 0, subset, ans); // Start from index 0
    return ans;
}


int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);

    for (auto &s : ans) {
        cout << "[ ";
        for (int x : s) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
