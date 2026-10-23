class Solution {
public:
bool isSorted(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]) return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();
            while (!isSorted(nums)) {
            int idx = 0, minSum = INT_MAX;
            for (int i = 0; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {      
                    minSum = s;
                    idx = i;
                }
            }
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }
        return ops;
    }
};