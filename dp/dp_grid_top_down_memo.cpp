class Solution {
public:
    int find(int x, int y, vector<vector<int>>&dp, vector<pair<int,int>> &mov, int m, int n) {
        if(x == 0 && y == 0) {  // add 1 if reached to 0,0
            return dp[0][0] = 1;
        }
        if(x<0 || x>=m || y<0 || y>=n) // dont go out of boundry
            return 0;
        
        if(dp[x][y]!=0)
            return dp[x][y];  // return if x,y is already calculated
        
        int cnt = 0;
        for(auto i: mov) {
            cnt+=find(x+i.first, y+i.second, dp, mov, m, n); // get count of all ways to reach at x,y by calling all possible movements.
        }
        return dp[x][y]=cnt; // store the count calculated for memo.
    }
    int uniquePaths(int m, int n) {
        vector<pair<int,int>>mov = {{-1,0},{0,-1}}; // all possible moves
        vector<vector<int>>dp(m, vector<int>(n,0)); // memo.
        
        return find(m-1,n-1,dp,mov,m,n);
    }
};
