#include <bits/stdc++.h> 
using namespace std;


int subseq (vector<int>&a, int ind, vector<int>&res,int &csum) {
    int result = 0;
    if(ind > 2) {
        if(csum==0) {
        result=1;
        }
        return result;
    }
    
    int left = subseq(a,ind+1,res,csum);

    res.push_back(a[ind]);
    csum-=a[ind];
    int right = subseq(a,ind+1,res,csum);
    csum+=a[ind];
    res.pop_back();
    return left + right;  // return the count from both the calls to the prev call.
    
    
    
}
int main() {
    vector<int>a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);

  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    int sum = 3;
    vector<int>res;
    int ans = subseq(a,0,res,sum);
    cout<<ans;

    return 0;
    
}
