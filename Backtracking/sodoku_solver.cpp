//given a 9*9 sodoku board with char 2D array. Solves the sodku by backtracking.
//INPUT:[
//["5","3",".",".","7",".",".",".","."],
//["6",".",".","1","9","5",".",".","."],
//[".","9","8",".",".",".",".","6","."],
//["8",".",".",".","6",".",".",".","3"],
//["4",".",".","8",".","3",".",".","1"],
//["7",".",".",".","2",".",".",".","6"],
//[".","6",".",".",".",".","2","8","."],
//[".",".",".","4","1","9",".",".","5"],
//[".",".",".",".","8",".",".","7","9"]
//]

class Solution {
public:
    
    vector<char>callOpt(vector<vector<char>> board, int i, int j){ //gives the available options for a particular block.
        char c[9]={'1','2','3','4','5','6','7','8','9'};   // eliminating these chars as i check row,column, 3*3 local block. If not cancelled include in return.
        for(int a = 0;a<9;++a){ // row
            if(board[a][j]!='.')
            c[(board[a][j]-'0')-1] = '0';
        }
         for(int a = 0;a<9;++a){ // column 
            if(board[i][a]!='.')
            c[(board[i][a]-'0')-1] = '0';
        }
        int x[3]={0,3,6};
        
        i=i/3; // locally check for 3*3 matrix
        j=j/3;
        int minx=x[i], maxx =minx+2 , miny=x[j] ,maxy =miny+2;
        
        for(int m = minx; m<=maxx;m++){
            for(int n = miny;n<=maxy;n++){
                if(board[m][n]!='.')
                c[(board[m][n]-'0')-1]='0';
            }
        }
        vector<char>res;
        for(auto w:c){
            if(w!='0')
                res.push_back(w);
        }
        return res; // return all the options
        
    }
    int solve(vector<vector<char>>& board, int i, int j){
        if(i==9 && j==0){
            for(int i = 0;i<9;++i){
                for(int j = 0;j<9;++j){
                    cout<<board[i][j]<<" ";
                }cout<<endl;
            }
            return 1;
        }
        int x;
        if(board[i][j]=='.'){
            vector<char>opt=callOpt(board, i, j);
            
           
                for(auto c:opt){
        
                    board[i][j]=c;
                    
                    x = j<9? solve(board,i,j+1):solve(board,i+1,0);
                    if(x==1)
                        return 1;
                 
                }
            board[i][j]='.';
                
            
        }
        else{
           int x = j<9? solve(board,i,j+1):solve(board,i+1,0);
            if(x==1)
                return 1;
        }
        return 2;
    }
    void solveSudoku(vector<vector<char>>& board) {
    int x = solve(board,0,0);
  
    }
};
