#include <bits/stdc++.h> 
using namespace std;


void subseq (vector<int>&a, int ind, vector<int>&res,int &csum) {
    if(ind > 4) {
        if(csum==0) { // extra cond to check if sum has reached
        for(auto i : res)
            cout<<i<<" ";
        cout<<endl;
        }
  
        return;
    }
    
    subseq(a,ind+1,res,csum);  // ignore the current ele
    
    res.push_back(a[ind]);  // pick the current ele
    csum-=a[ind];
    subseq(a,ind+1,res,csum);
    
    csum+=a[ind];  // when coming back make the sum as it was 
    res.pop_back();
    return;
    
    
}
int main() {
    vector<int>a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(6);
    
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    int sum = 6;
    vector<int>res;
    subseq(a,0,res,sum,sum);

    return 0;
    
}
