// URL: https://www.geeksforgeeks.org/problems/aggressive-cows/0
#include <bits/stdc++.h>
using namespace std;

bool canweplace(vector<int> &stalls, int k, int m){
    int cntCows = 1;
    int last = stalls[0];
    for (int i = 1; i < stalls.size();i++){
        if (stalls[i]-last>=m){
            cntCows++;
            last = stalls[i];
        }
    }
    return cntCows >= k;
}

    int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int l = 1;
    int h = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
    int ans = -1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if(canweplace(stalls,k,m))
        {
            ans = m;
            l = m + 1;
        }
        else{
        
            h = m - 1;
        }
    }
    return ans;
}

int main() {
    
    return 0;
}