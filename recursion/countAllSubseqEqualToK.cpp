#include <bits/stdc++.h> 
using namespace std;

 
int subseq (vector<int>a, int ind, int csum, int &cnt) { // maintain the count or use a global variable.
    if (ind == 4) {  // get all the subseqences here.
        if(csum==0) { // this means sum becomes k
            // for(auto i : res) {
            //     cout<<i<<" ";
            // } cout<<endl;
            return ++cnt;  // add to count.
        }
        return cnt;
    }
    
   cnt = subseq(a,ind+1,csum,cnt);  // not choosing the current element
    csum-=a[ind];   // choosing the current element. ( csum is k at the start )
    cnt = subseq(a,ind+1,csum,cnt); 
    
    return cnt;
   
 
}
int main() {
    vector<int>a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(3);
    a.push_back(3);
    
    int cnt = 0;
    int sum = 6;
    cnt = subseq(a,0,sum,cnt);
    cout<<cnt;
    return 0;
}
