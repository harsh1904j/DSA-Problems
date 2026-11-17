class Solution {
    int cnt[10] = {};
    vector<int> res;
    void solve(int pos, int num) {
        if (pos == 3) {
            res.push_back(num);
            return;
        }
        for (int d = 0; d < 10; d++) {
            if (cnt[d] == 0) continue;
            if (pos == 0 && d == 0) continue;
            if (pos == 2 && d % 2 == 1) continue;
            cnt[d]--;
            solve(pos + 1, num * 10 + d);
            cnt[d]++;
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        for (int i = 0; i < digits.size(); i++) {
            cnt[digits[i]]++;
        }
        solve(0, 0);
        return res;
    }
};