#include <bits/stdc++.h>
int find(int ind, int mw, vector<vector<int>> &dp, vector<int> &w, vector<int> &v) { // reducing the max weight to 0
    if(ind == w.size()-1) {
       return mw >= w[ind] ? dp[ind][mw] = v[ind] : dp[ind][mw] = 0;
    }
    
    if(dp[ind][mw] != -1)
        return dp[ind][mw];
    int t = INT_MIN, nt = 0;
    if(mw >= w[ind]) {
        t = v[ind] + find(ind+1, mw-w[ind], dp, w, v); // take
    }
    nt = find(ind+1, mw, dp, w ,v); // not take
    return dp[ind][mw] = max(t,nt);
    
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>>dp(weight.size(), vector<int>(maxWeight+1, 0)); // -1 for recursion, 0 for tabulation
    //return find(0, maxWeight, dp, weight, value);
    for(int i = weight[0]; i<=maxWeight; ++i) {
        dp[0][i] = value[0];
    }
    for(int i = 1; i<weight.size(); ++i) {
        for(int j = 0; j<=maxWeight; ++j) {
            int t = INT_MIN;
            if (j >= weight[i])
                 t = value[i] + dp[i-1][j - weight[i]]; // converted from recursion.
            int nt = dp[i-1][j];
            
            dp[i][j] = max(t,nt);
        }
    }
    return dp[weight.size()-1][maxWeight];
    
}
