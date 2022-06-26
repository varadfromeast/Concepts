#include <bits/stdc++.h> 
using namespace std;


void subseq(vector<int>&a,vector<int>&res,int ind) { // diff bw &res and res
                                                     // pass by ref vs pass by value is a lot when it comes to time taken.
                                                     // pass by value is heavy bc for each call a new copy of the vector is used in the memory,
                                                     // while, in pas by ref, the same memory location that was first assigned is used always.
    if (ind == 3) {
        for(auto i : res) {
            cout<<i<<" ";
        }cout<<endl;
        return;
    }
    
    subseq(a,res,ind+1);     // dont't take curr element in ans vector
    res.push_back(a[ind]);  // after coming back from last permutation, include the current element in ans vector
    subseq(a,res,ind+1);    // pass the current ans vector to next call, so that permutations can now happen on this vector.
    
    res.pop_back();  // when coming back from a prev push_back call, pop_back so that next permutations can happen properly.
    return;
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
