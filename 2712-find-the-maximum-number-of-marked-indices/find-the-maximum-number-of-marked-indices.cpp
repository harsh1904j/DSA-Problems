class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        for (int j = n / 2; j < n && i < n / 2; j++) {
            if (2LL * nums[i] <= nums[j]) {
                i++;
            }
        }
        return 2 * i;
    }
};