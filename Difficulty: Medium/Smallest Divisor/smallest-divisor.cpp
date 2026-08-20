class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
		while(low<=high){
		         int mid = low + (high-low)/2;
		         long long sum = 0;
		         int n = nums.size();
		         for(int i = 0; i < n; i++){
		         sum += ceil((double)(nums[i]) / (double)(mid));
		         }
		         if(sum <= threshold){
		             high = mid - 1;
		         }
		         else{
		             low = mid + 1;
		         }
		     }
		     return low;
        
    }
};
