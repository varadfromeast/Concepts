#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n = 5;
    vector<int>dp(n+1, 0);
    dp[1] = 1; // build from base case to req answer
    
    for(int i = 2; i <= n; ++i) { 
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout<<dp[n];

    return 0;
    
}
