class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<pair<int,int>>mov = {{-1,0},{0,-1}};
        vector<vector<int>>dp(m, vector<int>(n,0));
        
        dp[0][0] = 1;
      
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n ; ++j) {
                if(i==0 && j == 0)
                    continue;
                int l = 0, r = 0;
                if(i-1 >=0) {
                    l = dp[i-1][j];
                }
                if(j-1>=0) {
                    r = dp[i][j-1];
                }
                dp[i][j] = l + r;
            }
        }
        return dp[m-1][n-1];
    }
};
