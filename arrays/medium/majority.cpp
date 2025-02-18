// url : -https: // leetcode.com/problems/majority-element/description/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int m = nums.size() / 2;
    unordered_map<int, int> hash;
    for (auto num : nums)
    {
        hash[num]++;
        if (hash[num] > m)
            return num;
    }
    return 0;
}

// int majorityElement(vector<int> &nums)
// {
//     // Step 1: Find the candidate
//     int candidate = 0, count = 0;
//     for (int num : nums)
//     {
//         if (count == 0)
//         {
//             candidate = num;
//         }
//         count += (num == candidate) ? 1 : -1;
//     }

//     // Step 2: Verify the candidate
//     count = 0;
//     for (int num : nums)
//     {
//         if (num == candidate)
//         {
//             count++;
//         }
//     }

//     return (count > nums.size() / 3) ? candidate : -1;
//     }

int main()
{
    vector<int> arr = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    cout << majorityElement(arr);

    return 0;
}
