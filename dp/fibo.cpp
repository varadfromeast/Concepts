#include <bits/stdc++.h> 
using namespace std;

int fib(int n, vector<int> &dp) {
    if(n <=1 )
        return n;
    
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = fib(n-2,dp) + fib(n-1,dp);
    
}
int main() {
    int n = 4; // find this fib number
    vector<int>dp(n+1, -1);
    
    cout<<fib(n,dp);

    return 0;
    
}
