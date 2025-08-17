// URL:
#include <bits/stdc++.h>
using namespace std;

int reverseDigits(int n,int rev=0) {
    if (n==0) return rev;
    return reverseDigits(n/10,(rev*10)+n%10);
}


int main() {
    cout<<reverseDigits(123);
    return 0;
}
