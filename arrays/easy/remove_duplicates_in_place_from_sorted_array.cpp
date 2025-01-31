// URL:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    set<int> s1;
    for (auto num : arr)
    {
        s1.insert(num);
    }
    arr.clear();
    for (auto num : s1)
    {
        arr.push_back(num);
    }
    int k = s1.size();
    return k;
}

int main()
{

    return 0;
}