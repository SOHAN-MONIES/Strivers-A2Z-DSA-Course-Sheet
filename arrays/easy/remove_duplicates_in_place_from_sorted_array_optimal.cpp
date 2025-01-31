// URL:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <vector>
#include <iostream>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j <= nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}
int main()
{

    return 0;
}