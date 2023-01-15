class Solution {
public:
    int MX = 1e5;
//     int func(int i, int amt, vector<int> &coins, vector<vector<int>> &dp) {
//         if(i == 0) {
//             if(amt % coins[0] == 0) {
//                 return amt/coins[0];
//             }
//             else {
//                 return MX;
//             }
//         }

//         if(dp[i][amt] != -1)
//             return dp[i][amt];

//         int np = func(i-1, amt, coins, dp);
//         int p = MX;
//         if(amt >= coins[i]) {
//             p = min(np, 1 + func(i, amt - coins[i], coins, dp));
//         }
//         return dp[i][amt] = min(p, np);
        
//     }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,0));
      
        for(int j = 0; j<=amount; ++j) { // initialise from 0. Just look at base case from top_down method. Its the same.
            if(j % coins[0] == 0) 
                dp[0][j] = j/coins[0];
            else
                dp[0][j] = MX;
        }
      
       for(int i =1; i<coins.size(); ++i) { // traversal is reversed from top_down. check commented code.
            for(int j = 0; j<=amount; ++j) {
                int p = MX;
               if(j >= coins[i]) {
                   p = 1 + dp[i][j - coins[i]]; // Same logic as previous.
               }
               dp[i][j] = min(dp[i-1][j], p);
            }
        }
        return dp[coins.size()-1][amount] == MX ? -1 : dp[coins.size()-1][amount];

    }
};
