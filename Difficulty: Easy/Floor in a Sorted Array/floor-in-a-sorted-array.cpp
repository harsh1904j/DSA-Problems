class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
       int n = arr.size();
       int low = 0, high = n - 1;
       int floorVal = -1;

       while (low <= high) {
           int mid = low + (high - low) / 2;
           if (arr[mid] <= x) {
               floorVal = mid;
               low = mid + 1; 
           } else {
               high = mid - 1;
           }
       }
       return floorVal;
    }
};
