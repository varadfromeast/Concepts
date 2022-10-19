#include <bits/stdc++.h>
int find(int ind, int mw, vector<vector<int>> &dp, vector<int> &w, vector<int> &v) {
    if(ind == w.size()-1) {
       return mw >= w[ind] ? dp[ind][mw] = v[ind] : dp[ind][mw] = 0;
    }
    
    if(dp[ind][mw] != -1)
        return dp[ind][mw];
    int t = INT_MIN, nt = 0;
    if(mw >= w[ind]) {
        t = v[ind] + find(ind+1, mw-w[ind], dp, w, v);
    }
    nt = find(ind+1, mw, dp, w ,v);
    return dp[ind][mw] = max(t,nt);
    
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>>dp(weight.size(), vector<int>(maxWeight+1, 0));
    vector<int>dpo(maxWeight+1, 0);
    //return find(0, maxWeight, dp, weight, value);
    for(int i = weight[0]; i<=maxWeight; ++i) {
        dpo[i] = value[0]; // only using 1 d array.
    }
    for(int i = 1; i<weight.size(); ++i) {
        for(int j = maxWeight; j>=0; --j) { // filling from right, since, think about it only that information is required for the new row. 
          // if filled from left then prev info required for current will be tampered.
            int t = INT_MIN;
            if (j >= weight[i])
                 t = value[i] + dpo[j - weight[i]];
            int nt = dpo[j];
            
            dpo[j] = max(t,nt);
        }
    }
    return dpo[maxWeight];
    
}
