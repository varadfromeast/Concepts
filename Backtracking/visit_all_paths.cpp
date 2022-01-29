//starting from (0,0) go to (2,2) while printing all paths.
void all(int m, int n, int visited[3][3], string curr, int step){ 
    if(m==2 && n == 2){
        for(int i = 0;i<3;++i){
            for(int j = 0;j<3;++j){
                cout<<visited[i][j]<<" ";
            }cout<<endl;
        }
        cout<<curr<<endl<<endl;
        return;
    }
    if(m<0 || n<0 || m>2 || n>2 || visited[m][n]!=0){
        return;
    }
    visited[m][n] = step;
    all(m+1,n,visited,curr+'d',step+1);
    all(m,n-1,visited,curr+'l',step+1);
    all(m-1,n,visited,curr+'u',step+1);
    all(m,n+1,visited,curr+'r',step+1);
    
    visited[m][n]=0;

}
    
int main() {
 
    int visited[3][3]{
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
  
    string res="";
    all(0,0,visited,res,1);
}
