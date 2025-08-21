// URL:
#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s1, string s2) {
    int n1=s1.size();
    int n2=s2.size();
    int i=0;
    int j=0;
    int cnt=0;
    while(i<n1&&j<n2){
        if(s1[i]==s2[j]){
            i++;
            j++;
            cnt++;
        }
        else{
            j++;
        }

    }
    return cnt==n1;

}
int main() {
   string s1="abc";
    string s2="ahbgdc";
    cout<<isSubsequence(s1,s2);

    return 0;
}
