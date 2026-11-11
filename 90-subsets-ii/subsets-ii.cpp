class Solution {
public:
vector<vector<int>> res;
    void solve(vector<int>& nums, vector<int>& cur, int ind) {
        res.push_back(cur);                       
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            solve(nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   
        vector<int> cur;
        solve(nums, cur, 0);
        return res;
    }
};