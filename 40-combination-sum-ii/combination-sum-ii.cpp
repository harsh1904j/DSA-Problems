class Solution {
public:
    void solve(int idx, int target, vector<int>& c, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i < c.size(); i++) {
            if (i > idx && c[i] == c[i - 1]) continue;
            if (c[i] > target) break;  
            cur.push_back(c[i]);                
            solve(i + 1, target - c[i], c, cur, res); 
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        solve(0, target, candidates, cur, res);
        return res;
    }
};