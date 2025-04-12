// URL:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, map<int, int>> mpp;
    mpp[0][0] = 1;
    mpp[1][1] = 2;
    for (auto c : mpp)
    {
        for (auto r : c.second)
        {
            cout << r.first << " " << r.second << endl;
        }
    }
    return 0;
}