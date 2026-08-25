class Solution {
  public:
  int lowerBound(vector<int>& arr, int target) {
  int n = arr.size();
  int low = 0, high = n-1;
  int ans = n;
  while(low<=high){
      int mid = (low + high)/2;
      if(arr[mid] >= target){
          ans = mid; 
          high = mid - 1;
      }
      else{
          low = mid + 1;
      }
  }
  return ans;
}
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int cnt_max = 0;
        int ind = -1;
        for(int i = 0; i < n ; i++){
            int cnt = m - lowerBound(arr[i], 1);
        if(cnt > cnt_max){
            cnt_max = cnt;
            ind = i;
        }
    }
    return ind;
  }
};