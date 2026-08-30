class Solution {
  public:
    string frequencySort(string &s) {
        map<char, int> freq;
        for (char c : s) freq[c]++;
        int n = s.size();
        vector<string> buckets(n + 1, "");
        for (auto it = freq.begin(); it != freq.end(); it++) {
            char ch = it->first;
            int cnt = it->second;
            buckets[cnt] += string(cnt, ch);
        }

        string result;
        for (int i = 1; i <= n; i++) {
            result += buckets[i];
        }
        return result;
    }
};