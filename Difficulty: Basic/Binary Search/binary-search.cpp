class Solution {
  public:
  bool bS(vector<int>& arr, int low, int high, int target){
    if(low > high) return false;
    int mid = (low + high) / 2;
    if(arr[mid] == target) return true;
    else if(target > arr[mid]) return bS(arr, mid+1, high, target);
    return bS(arr, low, mid-1, target);
}
    bool binarySearch(vector<int>& arr, int k) {
        int n = arr.size();
        return bS(arr, 0, n-1, k);
    }
        
};