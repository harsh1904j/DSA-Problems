class Solution {
public:
int arrangeCoins(int n) {
    long long low = 1, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long coinsNeeded = mid * (mid + 1) / 2;
        if(coinsNeeded <= n){
            ans = mid;
            low= mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (int)ans;
    }
};