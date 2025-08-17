// URL:https://leetcode.com/problems/string-to-integer-atoi/
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    long long ans = 0;  // use long long for accumulation
    int negflag = 0;
    int i = 0;

    // 1. skip leading spaces
    while (i < s.length() && s[i] == ' ')
        i++;

    // 2. check sign
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') negflag = 1;
        i++;
    }

    // 3. convert digits
    while (i < s.length() && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');

        // check overflow
        if (!negflag && ans > INT_MAX) return INT_MAX;
        if (negflag && -ans < INT_MIN) return INT_MIN;

        i++;
    }

    // 4. apply sign
    if (negflag) ans = -ans;

    return (int)ans;
}

int myAtoi1(string s) {
    int i=0;
    int negflag=0;
    long long ans=0;

    while(i<s.length() && s[i]==' '){
        i++;
    }

    if(i<s.length()&&(s[i]=='+'||s[i]=='-')){
        if(s[i]=='-') negflag=1;
        i++;
    }
    while(i<s.length()&&isdigit(s[i])){
        ans=ans*10+(s[i]-'0');
        if(!negflag&&ans>INT_MAX) return INT_MAX;
        if(negflag&&-ans<INT_MIN) return INT_MIN;
        i++;
    }
    if(negflag) ans=-ans;






    return ans;
}
int main() {
    cout<<myAtoi("1231231231311133")<<endl;
    cout<<myAtoi1("1231231231311133");
    return 0;
}
