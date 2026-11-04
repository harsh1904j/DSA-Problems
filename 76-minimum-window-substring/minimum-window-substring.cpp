class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int l = 0, r = 0, minlen = INT_MAX, cnt = 0;
        int sInd = -1;
        unordered_map<char, int> mpp;
        for(int i = 0; i < n; i++) mpp[t[i]]++;
        while(r < m){
            if(mpp[s[r]] > 0) cnt++;
            mpp[s[r]]--;
            while(cnt == n){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sInd = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return sInd == -1? "" : s.substr(sInd, minlen);
    }
};