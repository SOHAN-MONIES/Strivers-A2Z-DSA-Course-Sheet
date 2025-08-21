// URL:
#include <bits/stdc++.h>
using namespace std;

void printSubsequenceSum(int i,vector<int> &temp,int s,int sum,vector<int> &arr) {
    if (i==arr.size()) {
        if (s==sum) {
            for (auto it:temp) cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    temp.push_back(arr[i]);
    s+=arr[i];
    printSubsequenceSum(i+1,temp,s,sum,arr);
    s-=arr[i];
    temp.pop_back();
    printSubsequenceSum(i+1,temp,s,sum,arr);
}




int main() {
    vector<int> arr={1,2,1};
    vector<int> temp;
    printSubsequenceSum(0,temp,0,2,arr);
}
