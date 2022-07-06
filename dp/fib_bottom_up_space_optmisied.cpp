#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n = 5;
    int prev1 = 0, prev2 = 1, ans = 0;  // not using dp vector, saves up space
    
    for(int i = 2; i <= n; ++i) {
        ans = prev1 + prev2;
        
        prev1 = prev2;
        prev2 = ans;
    }
    
    cout<<ans;

    return 0;
    
}
