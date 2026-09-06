class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long left = 0;
        while(left < n){
            if(left != nums[left]) return left;
            left++;
        }
        return n;
    }
};