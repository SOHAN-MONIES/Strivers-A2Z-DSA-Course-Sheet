vector<int> intersection1(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> interArr;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            interArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return interArr;
}