// URL:
#include <bits/stdc++.h>
using namespace std;

void printMsg(int n)
{
  
    if (n == 5)
        return;
    printMsg(++n);
    cout << n << "  ";
   
}

int main()
{

    printMsg(1);
    return 0;
}