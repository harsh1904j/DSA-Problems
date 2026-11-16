class Solution {
    int solve(int k, int len) {
        if (len == 1) {
            return 0;
        }
        int half = len / 2;
        if (k <= half) {
            return solve(k, half);
        }
        return solve(k - half, half) + 1;
    }
public:
    char kthCharacter(int k) {
        int len;
        for (len = 1; len < k; len *= 2) {
        }
        int shifts = solve(k, len);
        return 'a' + shifts % 26;
    }
};