// URL:
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr,int element,int low,int high) {
    int mid=(low+high)/2;
    if (low > high) return -1;
    if (arr[mid]==element) {
        return mid;
    }
    else if (arr[mid]>element) {
        return search(arr,element,low,mid-1);
    }
    else {
        return search(arr,element,mid+1,high);
    }

}

int main() {
    vector<int> arr={1,2,3,4,5};
    cout<<search(arr,8,0,arr.size()-1);
    return 0;
}
