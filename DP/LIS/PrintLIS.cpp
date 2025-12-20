// URL:https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Print Longest Increasing Subsequence (LIS)

Problem:
Given an array `arr`, find **one actual Longest Increasing Subsequence**
(not just its length).

-------------------------------------------------
Idea:

We use classic LIS DP (O(n²)) along with a `hash[]` array
to **reconstruct the subsequence path**.

-------------------------------------------------
State Definition:

dp[i]:
- Length of the LIS ending at index `i`

hash[i]:
- Stores the index of the previous element in the LIS ending at `i`
- Used to reconstruct the subsequence

-------------------------------------------------
Steps:

1️⃣ Initialization:
- dp[i] = 1 for all i (each element is an LIS of length 1)
- hash[i] = i (each element points to itself initially)

2️⃣ DP Computation:
For each index `i` from 0 to n-1:
    For each previous index `prev` from 0 to i-1:
        If arr[i] > arr[prev] AND
           dp[prev] + 1 > dp[i]:
            dp[i] = dp[prev] + 1
            hash[i] = prev

3️⃣ Find LIS Ending Index:
- Find index `i` where dp[i] is maximum
- This is the last element of the LIS

4️⃣ Reconstruct LIS:
- Start from index `i`
- Push arr[i] into answer
- Move to hash[i] repeatedly
- Stop when hash[i] == i

(Note: Sequence is built in reverse order)

5️⃣ Reverse the result to get correct LIS order
(optional if reverse is commented out)

-------------------------------------------------
Final Answer:
The vector `ans` contains one Longest Increasing Subsequence.

-------------------------------------------------
Time Complexity:
O(n²)

-------------------------------------------------
Space Complexity:
O(n)

-------------------------------------------------
🎯 Intuition:
- dp finds the LIS length
- hash remembers the path
- Backtracking through hash reconstructs the actual sequence

-------------------------------------------------
*/

vector<int> getLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }

    int i = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> ans;
    ans.push_back(arr[i]);
    int next = hash[i];
    while (next != i)
    {
        ans.push_back(arr[next]);
        i = next;
        next = hash[i];
    }
    return ans;
}
int main()
{
    vector<int> arr = {5, 4, 11, 1, 16, 8};
    vector<int> ans = getLIS(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}