// URL:
#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string b) {
    int ans=0;
    int pow_i=0;
    for(int i=b.size()-1;i>=0;i--){
        ans+=pow(2,pow_i)*(b[i]-'0');
        pow_i++;
    }

    return ans;

}

int main() {
    cout<<binaryToDecimal("0");
    return 0;
}
