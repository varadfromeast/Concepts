#include <bits/stdc++.h> 
using namespace std;


void subseq(vector<int>a,vector<int>res,int ind) {
    if (ind == 3) {
        for(auto i : res) {
            cout<<i<<" ";
        }cout<<endl;
        return;
    }
    
    subseq(a,res,ind+1);     // dont't take curr element in ans vector
    res.push_back(a[ind]);  // after coming back from last permutation, include the current element in ans vector
    subseq(a,res,ind+1);    // pass the current ans vector to next call, so that permutations can now happen on this vector.
}
int main() {
    vector<int>a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    
    vector<int>res;
    subseq(a,res,0);
    return 0;
}
