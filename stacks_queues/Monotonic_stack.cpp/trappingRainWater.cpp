// URL:
#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int> arr)
{
    int n = arr.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < leftMax[i] && arr[i] < rightMax[i])
        {
            total += min(leftMax[i], rightMax[i]) - arr[i];
        }
    }
    return total;
}
// int trap(vector<int> &height)
// {
//     int n = height.size();
//     vector<int> leftMax(n), rightMax(n);
//     leftMax[0] = height[0];
//     for (int i = 1; i < n; i++)
//     {
//         leftMax[i] = max(leftMax[i - 1], height[i]);
//     }
//     rightMax[n - 1] = height[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         rightMax[i] = max(rightMax[i + 1], height[i]);
//     }
//     int total = 0;
//     for (int i = 0; i < height.size(); i++)
//     {
//         if (height[i] < leftMax[i] && height[i] < rightMax[i])
//         {
//             total += min(leftMax[i], rightMax[i]) - height[i];
//         }
//     }
//     return total;
// }

int trap(vector<int> &height) // Initialize variables and start two-pointer approach
{
    int n = height.size();                    // Get the size of the input array
    int total = 0, leftMax = 0, rightMax = 0; // Initialize variables for total water and max heights
    int l = 0;                                // Left pointer
    int r = n - 1;                            // Right pointer
    while (l < r)                             // Iterate while pointers do not cross
    {
        if (height[l] <= height[r]) // If left height is smaller or equal to right height
        {
            if (leftMax > height[l]) // If leftMax is greater than the current left height
            {
                total += leftMax - height[l]; // Add trapped water at left
            }
            else
            {
                leftMax = height[l]; // Update leftMax
            }
            l = l + 1; // Move left pointer to the right
        }
        else // If right height is smaller than left height
        {
            if (rightMax > height[r]) // If rightMax is greater than the current right height
            {
                total += rightMax - height[r]; // Add trapped water at right
            }
            else
            {
                rightMax = height[r]; // Update rightMax
            }
            r = r - 1; // Move right pointer to the left
        }
    }
    return total; // Return the total trapped water
}

int main()
{
    vector<int> v1 = {3, 0, 1, 0, 4, 0, 2};
    cout << trap(v1) << endl;
    return 0;
}