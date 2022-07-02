class Solution {
public:    
    vector<pair<int,int>>p {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{1,1},{-1,1}};  // all the possible moves.
    void place(int n,int row, vector<vector<int>> &b, vector<vector<vector<int>>> &res) {
        if(row == n) {
            res.push_back(b);  // only if last row is reached, solution chess board is pushed to result.
            return;
        }
        
        for(int i = 0; i < n; ++i) {
            bool found = false;
            for (auto cod : p) {
                int x = row, y = i;
                while(x >= 0 && x < n && y >= 0 && y < n) {  // checking if queen is present on all possible moves.
                    if(b[x][y] == 1) {
                        found = true;
                        break;
                    }
                    x += cod.first;
                    y += cod.second;
                }
                if(found)
                    break;
            }
            if(!found) {
                b[row][i] = 1;
                place(n,row+1,b,res);
                b[row][i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<vector<int>>>res; // store multiple solution boards.
        vector<vector<int>>b;
        vector<vector<string>>ans;
        
        for(int i = 0;i<n;++i) {
            vector<int>now;
            for(int j = 0;j<n;++j)
                now.push_back(0);
            b.push_back(now);
        }
        
        place(n,0,b,res);
        for(int board = 0; board < res.size(); ++board) { // traverse through each solution board.
            vector<string>s1;
            for(int i = 0;i<n;++i) {
                string s;
                for(int j = 0; j<n; ++j) {
                    if(res[board][i][j]==0)
                        s+='.';
                    else
                        s+='Q';
                }
                s1.push_back(s);
            }
            ans.push_back(s1);
        }
        
        
        return ans;
    }
};
