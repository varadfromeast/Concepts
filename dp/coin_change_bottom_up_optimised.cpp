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
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1,0));
      
        vector<int>dpo(amount+1,0); // change vector dimension: use single array. Reason: No need to maintain 2d array. Use in line replace to basically
      // access same information.
      
        for(int i = 0; i <= amount; ++i) {
            dpo[i] = i % coins[0] == 0 ? i/coins[0] : MX; // same base case.
        }
        for(int i = 1; i<coins.size(); ++i) {
            for(int j =0; j<=amount; ++j) { // same traversal.
                int np = dpo[j];
                int p = MX;
                if(j >= coins[i]) {
                    p = 1 + dpo[j-coins[i]]; // same logic.
                }
                dpo[j] = min(p,np);
            }
        }
        return (dpo[amount] == MX) ? -1 : dpo[amount];

    }
};
