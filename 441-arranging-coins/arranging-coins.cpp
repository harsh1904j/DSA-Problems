class Solution {
public:
    int arrangeCoins(int n) {
    int i = 1;
    int ind = 0;
    while (n > 0) {
        n = n - i;
        if (n >= 0) ind = i;
        i++;
    }
    return ind;
    }
};