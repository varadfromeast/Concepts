class Solution { // Read problem statment for context
public:
    int MX = 1e5;
    int func(int i, int amt, vector<int> &coins, vector<vector<int>> &dp) { // go from last element to 0 for base case which will be used in later approaches.
        if(i == 0) {
            if(amt % coins[0] == 0) { // IMP base case. Treat base case as if only applying logic to a single element. 
                return amt/coins[0]; // Number of coins possible. easy.
            }
            else {
                return MX; // since minimum no of coins is stored, returning a MAX number helps in the min(_,_) function.
            }
        }

        if(dp[i][amt] != -1)
            return dp[i][amt];

        int np = func(i-1, amt, coins, dp);  // go to previous index if not taking current coin. No change to amount.
        int p = MX;
        if(amt >= coins[i]) {
            p = min(np, 1 + func(i, amt - coins[i], coins, dp)); // stay at current index, because infinite supply; BUT reduce amount.
        }
        return dp[i][amt] = min(p, np);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans = func(coins.size()-1, amount, coins, dp);
        return ans == MX ? -1 : ans;
    }
};
