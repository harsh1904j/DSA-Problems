class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int map[26] = {0};
            for(int j = i; j < n; j++){
                map[s[j]-'a']++;
            int maxi = 0;
            int mini = n; 
            for (int k = 0; k < 26; k++) {
                if (map[k] > 0) {
                    maxi = max(maxi, map[k]);
                    mini = min(mini, map[k]);
                }
            }
            sum += maxi-mini;
        }
    }
    return sum;
    }
};