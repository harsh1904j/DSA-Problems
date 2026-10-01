class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }
private:
    long long countPairs(vector<int>& nums, long long x) {
        long long res = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if ((long long)nums[l] + nums[r] <= x) {
                res += r - l;
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};