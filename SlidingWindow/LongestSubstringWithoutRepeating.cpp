// URL:https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
✅ Algorithm: Longest Substring Without Repeating Characters
(Using Sliding Window + Hash Map)

🧩 Problem:
Given a string `s`, find the length of the longest substring
that contains no repeating characters.

-------------------------------------------------
⚙️ Steps:

1. Initialize:
   - `maxLength = 0` → stores the length of the longest valid substring.
   - `unordered_map<char, int> mpp` → stores the last index of each character.
   - Two pointers for the sliding window: `i` (start) and `j` (end).

2. Iterate using `j` from 0 to n-1:
   - For each character `s[j]`:
     - If `s[j]` already exists in `mpp` **and**
       its previous index is ≥ current window start `i`,
       it means the character repeated inside the current window.
       👉 So, move the start pointer `i` to `mpp[s[j]] + 1`
       (just after the last occurrence of that character).

   - Update the last index of the character:
       `mpp[s[j]] = j`

   - Update maximum length:
       `maxLength = max(maxLength, j - i + 1)`

3. After the loop ends:
   - Return `maxLength` as the final answer.

-------------------------------------------------
🧠 Intuition:
- We use a **sliding window** to track the current substring without repeats.
- The hash map helps us skip over duplicate characters efficiently
  by remembering their last seen position.
- We never move the `i` pointer backward → O(n) complexity.

-------------------------------------------------
📊 Time Complexity: O(n)
   - Each character is visited at most twice (once by `j`, once by `i`).

💾 Space Complexity: O(k)
   - Where k = number of unique characters in the string (≤ 256).

-------------------------------------------------
🔢 Example:
Input: s = "abcabcbb"

Window movements:
i=0, j=0 → "a" → max=1
i=0, j=1 → "ab" → max=2
i=0, j=2 → "abc" → max=3
Encounter 'a' again → move i to 1
i=1, j=3 → "bca" → max=3
...
Final maxLength = 3 ("abc")

Output → 3
*/

int lengthOfLongestSubstring(string s)
{
    int maxLength = 0;
    unordered_map<char, int> mpp;
    int i = 0;
    for (int j = 0; j < s.size(); j++)
    {

        if (mpp.find(s[j]) != mpp.end() && mpp[s[j]] > i)
        {
            i = mpp[s[j]] + 1;
        }
        mpp[s[j]] = j;
        maxLength = max(maxLength, j - i + 1);
    }
    return maxLength;
}

int main()
{
    cout << lengthOfLongestSubstring("tmmzuxt");
    return 0;
}