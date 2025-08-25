// URL: 
#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b)
{
    pair<int, int> p1;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    p1.first = a;
    p1.second = b;
    return p1;
}
int main() {
    
    return 0;
}