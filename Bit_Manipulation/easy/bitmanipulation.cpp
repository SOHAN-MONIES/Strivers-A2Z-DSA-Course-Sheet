// URL:https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1
#include <bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i)
{
    // your code here
    int a = (num & (1 << (i - 1))) ? 1 : 0;
    int b = num | (1 << (i - 1));
    int c = num & ~(1 << (i - 1));

    cout << a << " " << b << " " << c;
}
int main()
{
    bitManipulation(8, 1);
    return 0;
}