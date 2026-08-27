class Solution {
  public:
    int median(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = INT_MAX; int high = INT_MIN;
        for(int i = 0; i < m; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n-1]);
        }
        int req = (m*n)/2;
        while(low<=high){
            int mid = low + (high-low)/2;
            int cnt = 0;
            for(int i = 0; i < m; i++){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(cnt <= req) low = mid+1;
            else high = mid-1;
        }
        return low;
        
    }
};
