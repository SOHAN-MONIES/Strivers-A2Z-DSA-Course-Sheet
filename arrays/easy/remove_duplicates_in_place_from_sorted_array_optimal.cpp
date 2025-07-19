// URL:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <vector>
#include <iostream>
using namespace std;
// ✅ Algorithm to Remove Duplicates from Sorted Array (In-Place)

// 1. Initialize pointer j = 0 → keeps track of unique element position.
// 2. Loop from i = 1 to end of array:
//    - If nums[i] != nums[j] → it's a new unique element.
//    - Move it to position j + 1 → nums[j + 1] = nums[i].
//    - Increment j.
// 3. Return j + 1 → the new size of unique elements.

int removeDuplicates(vector<int> &nums)
{
    int j = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            nums[j + 1] = nums[i];
            j++;
        }
    }
    return j + 1;
}
int main()
{

    return 0;
}