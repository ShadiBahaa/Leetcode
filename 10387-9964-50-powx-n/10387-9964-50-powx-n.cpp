class Solution {
public:
    double mpow(double x, long long n){
        if(n==0)return 1;
        if(n < 0)return 1 / mpow(x,-n);
        if(n%2){
            return x * mpow(x,n-1);
        }
        double res = mpow(x,n/2);
        return res*res;
    }
    double myPow(double x, int n) {
       return mpow(x,n);
    }
};