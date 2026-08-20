class Solution {
public:
int sumOfDiv(vector<int>& arr, int div){
    long long sum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        sum = sum + ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(sumOfDiv(nums, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};