#include <bits/stdc++.h>
using namespace std;

// Helper function to check if a pair of parentheses is of the same type (e.g., '(' and ')')
bool isSameType(char c1, char c2)
{
    // Check if c1 and c2 are matching pairs of parentheses
    if (c1 == '(' && c2 == ')') // Case for round brackets
    {
        return true; // Return true if it's a matching pair
    }
    else if (c1 == '{' && c2 == '}') // Case for curly brackets
    {
        return true; // Return true if it's a matching pair
    }
    else if (c1 == '[' && c2 == ']') // Case for square brackets
    {
        return true; // Return true if it's a matching pair
    }
    else
    {
        return false; // Return false if the pair doesn't match
    }
}

// Function to check if the string has balanced parentheses
bool isValid(string s)
{
    // Create an empty stack to hold opening brackets
    stack<char> st;

    // Loop through each character in the string
    for (auto c : s)
    {
        // If the character is an opening bracket, push it to the stack
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c); // Add the opening bracket to the stack
        }
        // If the character is a closing bracket
        else if (c == ')' || c == '}' || c == ']')
        {
            // If the stack is empty, it means there is no matching opening bracket
            if (st.empty())
            {
                return false; // Return false because it's unbalanced
            }
            // Check if the top of the stack matches the closing bracket
            if (isSameType(st.top(), c)) // If the top of the stack matches
            {
                st.pop(); // Pop the matching opening bracket from the stack
                continue; // Continue to the next character in the string
            }
            else
            {
                return false; // If the brackets don't match, return false (unbalanced)
            }
        }
    }

    // If the stack is empty after processing the entire string, return true (balanced)
    return st.empty(); // If the stack is empty, it means all brackets were matched and balanced
}

int main()
{
    // Test cases to check if the function works
    cout << isValid("()") << endl;       // Output: 1 (true) - Balanced parentheses
    cout << isValid("({[()]})") << endl; // Output: 1 (true) - Balanced parentheses
    cout << isValid("{[(])}") << endl;   // Output: 0 (false) - Unbalanced parentheses
    return 0;
}
