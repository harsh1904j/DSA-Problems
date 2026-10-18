class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        if(n < 0) N = -N;
        while(N){
            if(N % 2 == 1){
                ans = ans * x;
                N = N - 1;
            }
            else{
                x = x * x;
                N = N/2;
            }
        }
        if(n < 0) ans = 1.0/ ans;
        return ans;
    }
};