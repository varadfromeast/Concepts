class Solution {
public:
    void replace1(int x, int y, string &s) {
        if(x==y)
            return;
        char last = s[y];
        for(int i=y-1; i>=x; --i){
            s[i+1]=s[i];
        }
        s[x]=last;
    }
    
    void replace2(int x,int y,string &s) {
        if(x==y)
            return;
        char first = s[x];
        for(int i = x+1; i<=y; ++i) {
            s[i-1]=s[i];
        }
        s[y]=first;
    }
    bool find(int ind, int &count, string &s, int n, int k) {
        if(ind == s.size()) {
            if(count == k) {
                return true;
            }
            ++count;
            return false;
        }
        
        for(int i = ind; i<s.size(); ++i) {
            replace1(ind,i,s);  // rotate right
            if(find(ind+1,count,s,n,k)) {
                return true;
            }
            replace2(ind,i,s); // rotate left
        }
        return false;
    }
    string getPermutation(int n, int k) {
        int count = 1;
        string s;
        for(int i = 1;i<=n;++i) {
            s+=(i+'0'); // 1 2 3
        }
        find(0,count,s,n,k);
        return s;
    }
};
