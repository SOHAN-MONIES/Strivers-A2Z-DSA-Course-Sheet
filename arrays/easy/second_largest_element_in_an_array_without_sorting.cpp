// URL:-  same problem but without sort function
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*Logic to Find Second Largest in Array

Initialize:
- Set large to the first element.
- Set slarge (second largest) to -1.

Traverse the array:
- If you find a new number greater than large:
    - Update slarge = large.
    - Update large = current element.
- Else if the current element is between large and slarge (i.e. larger than slarge but less than large):
    - Update slarge = current element.*/

 int getSecondLargest(vector<int> &arr) {
       int n=arr.size();
       int large=arr[0];
       int slarge=-1;
       for(int i=1;i<n;i++){
           if(arr[i]>large){
               slarge=large;
               large=arr[i];
           }
           else if(arr[i]>slarge&&arr[i]<large){
               slarge=arr[i];
           }
       }
       return slarge;
    }
int main()
{

    return 0;
}
