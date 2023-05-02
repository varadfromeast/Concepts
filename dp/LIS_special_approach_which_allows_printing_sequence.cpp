class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>hash(n, -1);
        int ans = 0;
        int ind = 0;
        for(int i = 1; i<n; ++i) { // O(n^2) approach. 
            for(int j = 0; j<i; ++j) {
                if(nums[i] > nums[j]) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > ans) {
                ans = dp[i];
                ind = i;
            }
        }
        vector<int>res;
        while(ind != -1) {
            res.push_back(nums[ind]);
            ind = hash[ind];
        }
        return res;
        
    }
};
