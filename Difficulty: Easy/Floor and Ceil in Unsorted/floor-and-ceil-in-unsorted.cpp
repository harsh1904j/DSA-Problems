class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int low = 0, high = n - 1;
        int floorVal = -1, ceilVal = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] <= x) {
                floorVal = a[mid];
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }

        low = 0; 
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] >= x) {
                ceilVal = a[mid];
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return {floorVal, ceilVal};
        
    }
};