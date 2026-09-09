class Solution {
public:
    int strStr(string hs, string ne) {
    int n = hs.size(), m = ne.size();
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && hs[i + j] == ne[j]) j++;
        if (j == m) return i;
    }
    return -1;
    }
};