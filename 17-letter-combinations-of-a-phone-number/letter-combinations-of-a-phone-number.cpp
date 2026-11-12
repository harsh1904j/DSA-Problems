class Solution {
public:
       vector<string> result;
       string ans;
    void solve(string digits, int i, string mpp[]){
        if(i >= digits.size()){
            result.push_back(ans);
            return;
        }
        int number = digits[i] - '0';
        string value = mpp[number];
        for(int j = 0; j < value.size(); j++){
            ans.push_back(value[j]);
            solve(digits, i + 1, mpp);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string mpp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, 0, mpp);
        return result;
    }
};