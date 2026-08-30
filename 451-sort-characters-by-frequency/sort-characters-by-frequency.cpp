class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    int n = s.size();
    vector<string> buckets(n + 1, "");
    for (auto& [ch, cnt] : freq) {
        buckets[cnt] += string(cnt, ch);
    }

    string result;
    for (int i = n; i >= 1; i--) {
        result += buckets[i];
    }
    return result;
    }
};