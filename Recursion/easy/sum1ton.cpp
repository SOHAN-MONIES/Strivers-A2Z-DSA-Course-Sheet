// URL:
#include <bits/stdc++.h>
using namespace std;

int sum1ton(int n) {
    if (n==1) return 1;
    return n+sum1ton(n-1);
}

void printnnto1(int n) {
    if (n==0) return;
    cout<<n<<endl;
    printnnto1(n-1);
    cout<<n<<endl;


}


int main() {
    int a=sum1ton(3);
    printnnto1(5);
    return 0;
}
