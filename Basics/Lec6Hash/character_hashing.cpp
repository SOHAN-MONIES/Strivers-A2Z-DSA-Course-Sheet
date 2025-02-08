// URL:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    vector<int> hash(256, 0);
    string name = "sohan monie s";
    for (int i = 0; i < name.size(); i++)
    {
        hash[name[i]]++;
    }
    cout << hash[' '];
    return 0;
}