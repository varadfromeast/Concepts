int n =6;

bool safe(int places[6][6],int x,int y){
 
        int a = x, b = y;
        while(a>=0 && b>=0){
            if(places[a][b]==1)
                return false;
            a--;
            b--;
        }
        a=x-1,b=y;
        while(a>=0){
            if(places[a][b]==1)
                return false;
            a--;
        }
        a=x,b=y;
        while(a>=0 && b<n){
            if(places[a][b]==1)
                return false;
            a--;
            b++;
        }
    return true;
    
}

void display(int places[6][6]){
    for(int i = 0;i<6;++i){
        for(int j = 0; j<6;++j){
            cout<<places[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

int nqueens(int i,int places[6][6]){
    if(i == n){
        display(places);
        return 1;
    }
    int count = 0;
    for(int x = 0;x<n;++x){
        if(safe(places, i, x)){
            places[i][x]=1;
            count += nqueens(i+1,places);
            places[i][x]=0;
        }
    }
    return count;

}

int main() {

    int places[6][6] ={
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
    };
    
    cout<<nqueens(0,places);
}
