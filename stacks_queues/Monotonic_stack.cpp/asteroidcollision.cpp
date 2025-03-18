// URL:
#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(int N, vector<int> &asteroids)
{
    vector<int> ans;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0)
        {
            ans.push_back(asteroids[i]);
        }
        else
        {
            while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i]))
            {
                ans.pop_back();
            }
            if (ans.empty() || ans.back() < 0)
            {
                ans.push_back(asteroids[i]);
            }
            if (ans.back() == abs(asteroids[i]))
            {
                ans.pop_back();
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}