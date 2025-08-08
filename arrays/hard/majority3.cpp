// URL: https://leetcode.com/problems/majority-element-ii/description/
#include <bits/stdc++.h>
using namespace std;

/*
✅ Algorithm: Extended Boyer-Moore Voting Algorithm – Majority Element II

Problem:
- Find all elements in an array that appear more than ⌊n/3⌋ times.
- At most 2 such elements can exist.

Steps:
1. Initialize:
   - cand1, cand2 (two potential candidates)
   - mcnt1, mcnt2 = 0 (their counts)
2. First Pass (Find Potential Candidates):
   - For each number:
       a) If mcnt1 == 0 and current number != cand2:
             cand1 = current number, mcnt1 = 1
       b) Else if mcnt2 == 0 and current number != cand1:
             cand2 = current number, mcnt2 = 1
       c) Else if current number == cand1:
             mcnt1++
       d) Else if current number == cand2:
             mcnt2++
       e) Else:
             mcnt1--, mcnt2--
3. Second Pass (Verify Candidates):
   - Count actual frequencies of cand1 and cand2.
4. If freq1 > ⌊n/3⌋ → add cand1 to result.
5. If freq2 > ⌊n/3⌋ → add cand2 to result.

⚠️ Assumption:
- The result can have 0, 1, or 2 elements.

🕒 Time Complexity: O(n)
   - Two passes through the array.

🧠 Space Complexity: O(1)
   - Constant extra space, excluding output.
*/
vector<int> majorityElement(vector<int> &nums)
{
    vector<int> res;
    int cand1 = INT_MIN, mcnt1 = 0;
    int cand2 = INT_MIN, mcnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mcnt1 == 0 && nums[i] != cand2)
        {
            cand1 = nums[i];
            mcnt1 = 1;
        }
        else if (mcnt2 == 0 && nums[i] != cand1)
        {
            cand2 = nums[i];
            mcnt2 = 1;
        }
        else if (cand1 == nums[i])
        {
            mcnt1++;
        }
        else if (cand2 == nums[i])
        {
            mcnt2++;
        }
        else
        {
            mcnt1--;
            mcnt2--;
        }
    }
    int freq1 = 0;
    int freq2 = 0;
    for (auto num : nums)
    {
        if (num == cand1)
            freq1++;
        if (num == cand2)
            freq2++;
    }
    int mjn = nums.size() / 3;
    if (freq1 > mjn)
    {
        res.push_back(cand1);
    }
    if (freq2 > mjn)
    {
        res.push_back(cand2);
    }
    return res;
}

int main() {
    
    return 0;
}