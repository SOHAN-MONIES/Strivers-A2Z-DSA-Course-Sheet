// URL:
#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    if (start == end)
    {
        return 0;
    }
    vector<int> steps(99999, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [step, num] = pq.top();
        pq.pop();

        for (int i = 0; i < arr.size(); i++)
        {
            int prod = (num * arr[i]) % 100000;
            if (prod == end)
            {
                return step + 1;
            }
            if (step + 1 < steps[prod])
            {
                steps[prod] = step + 1;
                pq.push({steps[prod], prod});
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 5, 7};

    cout << minimumMultiplications(arr, 3, 10);
    return 0;
}