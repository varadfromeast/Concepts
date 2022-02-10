class Solution {
public:
    double power(double x, int n){ 
        if(n==0)
            return 1;
        double z = power(x,n/2); // after coming back from the base case. take the ans in 'z'
        if(n%2==0)
            return z*z;          // do ans * ans for exponent is even
        else
            return z*z*x;        // do ans * ans * original_number when exponent is odd
    }
    double myPow(double x, int n) { //x^n
        double res;
        if(n<0){
            res = 1 / power(x,abs(n));
        }
        else
            res = power(x,n);
        return res;
    }
};
