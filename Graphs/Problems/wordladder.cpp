// URL:https://leetcode.com/problems/word-ladder/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Word Ladder (Shortest Transformation Sequence)

Problem:
- Given two words (beginWord and endWord) and a dictionary wordList,
  transform beginWord into endWord by changing only one character at a time.
- Each transformed word must exist in wordList.
- Return the minimum number of transformations required.
- If transformation is not possible, return 0.

Steps:
1. Convert wordList into a set for O(1) lookup.
   - If endWord is not in set → return 0 (no possible transformation).

2. BFS Initialization:
   - Use a queue of pairs {currentWord, transformationLength}.
   - Start with {beginWord, 1}.

3. BFS Traversal:
   - While queue is not empty:
     - Pop {word, cnt}.
     - For each character position i in word:
       - Replace it with every character 'a' → 'z'.
       - If newWord == endWord → return cnt + 1.
       - If newWord exists in set:
           - Push {newWord, cnt + 1} into queue.
           - Erase newWord from set (to avoid revisiting).

4. If BFS completes without finding endWord, return 0.

⚠️ Assumptions:
- All words are of equal length.
- beginWord may or may not be in wordList.
- Transformations are case-insensitive (all lowercase assumed).

🕒 Time Complexity: O(N × L × 26)
   - N = number of words in wordList.
   - L = length of each word.
   - For each word, generate all possible transformations.

🧠 Space Complexity: O(N × L)
   - Queue and set storing words.
*/

int LadderLength(string beginWord, string endWord,
                 vector<string> &wordList)
{

    queue<pair<string, int>> q1;
    q1.push({beginWord, 1});
    set<string> st(wordList.begin(), wordList.end());
    if (st.find(endWord) == st.end())
        return 0;
    while (!q1.empty())
    {
        auto [word, cnt] = q1.front();
        string temp = word;
        q1.pop();
        for (int i = 0; i < word.size(); i++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
        
                word[i] = ch;
                if (word == endWord)
                    return cnt + 1;
                if (st.find(word) != st.end())
                {
                    q1.push({word, cnt + 1});
                    st.erase(word);
                    break;
                }
            }
            word = temp;
        }
    }
    return 0;
}

int main()
{
    vector<string> vec = {"a", "b", "c"};
    cout << LadderLength("a", "b", vec);
    return 0;
}