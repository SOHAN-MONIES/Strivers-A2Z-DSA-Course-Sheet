// URL:
#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans,string &temp,string &s,vector<int> &mpp){
    if(temp.size()==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<s.size();i++){
        if(i>0&&s[i-1]==s[i]&&!mpp[i-1]) continue;

        if(!mpp[i]){
            mpp[i]=1;
            temp+=s[i];
            solve(ans,temp,s,mpp);
            mpp[i]=0;
            temp.pop_back();
        }
    }
}

vector<string> findPermutation(string &s) {
    sort(s.begin(),s.end());
    vector<string> ans;
    string temp;
    vector<int> mpp(s.size(),0);
    solve(ans,temp,s,mpp);

    return ans;
}
int main() {
    string s="PRJJX";
    vector<string> ans=findPermutation(s);
    for (auto ele:ans) {
        cout<<ele<<endl;
    }
    return 0;
}
