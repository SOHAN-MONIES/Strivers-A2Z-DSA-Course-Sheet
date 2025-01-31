void rotate(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> v1 = nums;
    int j = 0;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + k <= n - 1)
        {
            nums[i + k] = v1[i];
        }
        else
        {
            nums[j] = v1[n - k + a];
            j++;
            a++;
        }
    }
    for (auto num : nums)
    {
        cout << num << " ";
    }
}