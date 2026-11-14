class Solution {
public:
bool isPalin(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}
void solve(int i, string s, vector<string>& path, vector<vector<string>>& res){
    if(i == s.size()){
        res.push_back(path);
        return;
    }
    for(int j = i; j < s.size(); ++j){
        if(isPalin(s, i, j)){
            path.push_back(s.substr(i, j-i+1));
            solve(j + 1, s, path, res);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0, s, path, res);
        return res;
    }
};