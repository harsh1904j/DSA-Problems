class Solution {
public:
    char findTheDifference(string s, string t) {
        int result = 0;
        for(int i : s) result ^= i;
        for(int j : t) result ^= j;
        return result;
    }
};