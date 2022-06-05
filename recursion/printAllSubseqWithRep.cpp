#include <bits/stdc++.h> 
using namespace std;


void subseq (vector<int>a, int ind, int csum, vector<int> res) {
    if(csum<0) // new condition to handle case when picking current element yields more value than target
        return;
    if(ind == 4) {  // all the possible combintations end up here.
        if (csum == 0) { // target = 0, correct combination.
        for(int i : res)
            cout<<i<< " ";
        cout<<endl;
        }
        return;
    }
  
        subseq(a,ind+1,csum,res);  // dont pick the current element and go to next index.
        csum -= a[ind]; 

        res.push_back(a[ind]);
        subseq(a,ind,csum,res);  // pick the current element again.
            
    
}
int main() {
    vector<int>a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(6);
    a.push_back(7);
    
    int sum = 7;
    vector<int>res;
    subseq(a,0,sum,res);
    return 0;
}
