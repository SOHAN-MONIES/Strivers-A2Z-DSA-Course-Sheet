// URL:
#include <bits/stdc++.h>
using namespace std;

void toBinary(int &n) {
    // your code here
    string s;
    while(n>0){
        if(n%2==1) s+='1';
        else s+='0';
        n=n/2;
    }
    reverse(s.begin(),s.end());
    n=stoi(s);
}

int main() {
    int n=13;
    toBinary(n);
    cout<<n;
    return 0;
}
