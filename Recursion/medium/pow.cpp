// URL: https://leetcode.com/problems/powx-n/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Fast Exponentiation (Iterative) – Power Function

Problem:
- Compute x raised to the power n → x^n.
- Handle both positive and negative exponents efficiently.

Steps:
1. Initialize:
   - ans = 1 (final result accumulator)
   - nn = n (convert to long long to avoid overflow issues)
2. Handle negative exponent:
   - If n < 0:
       - Set x = 1 / x
       - Set nn = -nn
3. Loop until nn > 0:
   - If nn is even:
       - Square the base: x = x * x
       - Divide exponent by 2: nn = nn / 2
   - Else (nn is odd):
       - Multiply ans by current base: ans = ans * x
       - Decrease exponent by 1: nn = nn - 1
4. Return ans as the result.

⚠️ Assumptions:
- n can be negative, zero, or positive.
- Handles large exponents using long long to prevent overflow.

🕒 Time Complexity: O(log n)
   - Exponent reduces by half in each iteration.

🧠 Space Complexity: O(1)
   - Uses only a few variables.
*/

double myPowIterative(double x, int n) {
    double ans=1;
    long long nn=n;
    if (n < 0) {
        x = 1 / x;
        nn = -nn;
    }
    while(nn>0){
        if(nn%2==0){
            x=x*x;
            nn=nn/2;
        }
        else{
            ans=ans*x;
            nn=nn-1;
        }
    }

    return ans;

}

// Only Works for small integer
double myPow1(double x, int n) {
    if (n==0) return 1;
    if (n<0) return 1/myPow1(x,-n);
    return x*myPow1(x,n-1);
}

/*
✅ Algorithm: Fast Exponentiation (Recursive) – Power Function

Problem:
- Compute x raised to the power n → x^n.
- Handle both positive and negative exponents efficiently.

Steps:
1. Base Case:
   - If n == 0 → return 1 (anything to the power 0 is 1).
2. Handle negative exponent:
   - If n < 0:
       - Set x = 1 / x
       - Set n = -n (convert to positive).
3. Recursive step:
   - Compute half = myPow(x, n/2).
4. Combine results:
   - If n is even → return half * half.
   - If n is odd  → return x * half * half.
5. Return the result.

⚠️ Assumptions:
- n can be negative, zero, or positive.
- Handles large exponents using long long to prevent overflow.

🕒 Time Complexity: O(log n)
   - Exponent reduces by half in each recursive call.

🧠 Space Complexity: O(log n)
   - Recursion depth is proportional to log n.
*/

double myPow(double x,int n) {
    if (n==0) {
        return 1.0;
    }
    long long nn=n;
    if (nn<0){
        x=1/x;
        nn=-nn;
    }
    double res= myPow(x,nn/2);
    if (nn %2==0) {
        return res*res;
    }
    else {
        return x*res*res;
    }
}

int main() {
    cout<<myPow(2,10);
    return 0;
}
