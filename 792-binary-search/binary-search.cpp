class Solution {
public:
int bS(vector<int>& arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) return bS(arr, mid+1, high, target);
    return bS(arr, low, mid-1, target);
}
    int search(vector<int>& nums, int target) {
        return bS(nums, 0, nums.size()-1, target);
    }
};