class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zeros = 0;
        int ones = 0;
        for(char i : s) if(i == '1') ones++;
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == '0') zeros++;
            else ones--;
            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};