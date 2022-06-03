#include <bits/stdc++.h> 
using namespace std;

int sum = 3; //given sum
void subseq(vector<int>a, vector<int>res, int ind, int csum) {
    if (ind == 3) { // go to final condition -> this is where we get all subsequences.
        if(csum==0) { // instead of printing all subseq. print the ones which has made the sum to be 0. 
            for(auto i : res) { // note that it is imp to go till ind == 3, because at this stage only we get all the permutations.
                cout<<i<<" ";
            } cout<<endl;
        }
        return;
    }
    //same code as print all subseq, just another variable which maintains the current sum. 
    subseq(a,res,ind+1,csum);
    csum = csum - a[ind]; // whatever the current sum is, subtract from it current element.
    res.push_back(a[ind]);
    subseq(a,res,ind+1,csum);
}
int main() {
    vector<int>a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    
    vector<int>res;
    subseq(a,res,0,sum); // give the final sum, because we are subtracting.
    return 0;
}
