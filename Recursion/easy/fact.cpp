#include<iostream>

using namespace std;
int sumOfDigits(int n) {
    // code here
    if(n==0) return 1;
    return n%10*sumOfDigits(n/10);
}


int main() {
 int a=sumOfDigits(2321);
 cout <<a;;
}