class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long x, long long n) {
        if (n == 0) return 1;
        long long half = power(x, n / 2);
        long long res = (half * half) % MOD;
        if (n % 2 == 1) res = (res * x) % MOD;
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;   
        long long oddPos = n / 2;         
        return (power(5, evenPos) * power(4, oddPos)) % MOD;
    }
};