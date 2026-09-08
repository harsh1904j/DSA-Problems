class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size(); 
    unordered_map<int, int> ans;
    vector<int> list;
    for(int i = 0; i < n; i++){
        ans[nums[i]]++;
    }
    for(int i = 1; i <=n; i++){
        if(ans[i]==0) list.push_back(i);
    }
    return list;
    }
};