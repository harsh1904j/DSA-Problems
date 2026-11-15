class Solution {
public:
    vector<string> answer;
    char path[40];
    int n;
    int target;
    const char* digits;
    void solve(int pos, int len, long long value, long long last) {

        if (pos == n) {
            if (value == target) {
                answer.push_back(string(path, len));
            }
            return;
        }
        long long current = 0;
        int k = len;
        if (pos != 0) {
            k = len + 1;       
        }
        for (int i = pos; i < n; i++) {
            if (i > pos && digits[pos] == '0') {
                break;
            }
            current = current * 10 + (digits[i] - '0');
            path[k] = digits[i];
            k++;
            if (pos == 0) {
                solve(i + 1, k, current, current);
            } else {
                path[len] = '+';
                solve(i + 1, k, value + current, current);
                path[len] = '-';
                solve(i + 1, k, value - current, -current);
                path[len] = '*';
                solve(i + 1, k, value - last + last * current, last * current);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        answer.clear();
        n = num.size();
        this->target = target;
        digits = num.c_str();
        solve(0, 0, 0, 0);
        return answer;
    }
};