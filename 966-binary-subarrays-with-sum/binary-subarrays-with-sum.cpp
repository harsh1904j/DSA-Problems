class Solution {
public:
int numOfSub(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int cnt = 0, l = 0, r = 0, sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numOfSub(nums, goal) - numOfSub(nums, goal - 1);
    }
};