class Solution {
public:
vector<vector<int>> res;
 void solve(vector<int>& nums, vector<int> cur, int ind){
    if(ind >= nums.size()){
        res.push_back(cur);
        return;
    }
    cur.push_back(nums[ind]);
    solve(nums, cur, ind + 1);
    cur.pop_back();
    solve(nums, cur, ind + 1);
 }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        solve(nums, cur, 0);
        return res;
    }
};