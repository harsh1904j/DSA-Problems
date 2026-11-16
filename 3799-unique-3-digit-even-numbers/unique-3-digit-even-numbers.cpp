class Solution {
    int cnt[10] = {};
    int solve(int pos) {
        if (pos == 3) {
            return 1;
        }
        int total = 0;
        for (int d = 0; d < 10; d++) {
            if (cnt[d] == 0) continue;
            if (pos == 0 && d == 0) continue;
            if (pos == 2 && d % 2 == 1) continue;
            cnt[d]--;
            total += solve(pos + 1);
            cnt[d]++;
        }
        return total;
    }
public:
    int totalNumbers(vector<int>& digits) {
        for (int i = 0; i < digits.size(); i++) {
            cnt[digits[i]]++;
        }
        return solve(0);
    }
};