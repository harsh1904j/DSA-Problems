class Solution {
public:
int maxEle(vector<int>& arr){
  int maxi = INT_MIN;
  int n = arr.size();
  for(int i = 0; i < n; i++){
    maxi = max(arr[i], maxi);
  }
  return maxi;
}
long long func(vector<int>& arr, int h){
    int n = arr.size();
    long long totalH = 0;
    for(int i = 0; i <= n-1; i++){
       totalH += ceil((double)arr[i] / (double)h);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = INT_MAX;
        int low = 1, high = maxEle(piles);
        while(low<=high){
            int mid = low + (high-low)/2;
            long long totalHours = func(piles, mid);
            if(totalHours <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};