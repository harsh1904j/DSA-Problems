class Solution {
  public:
  int func(int mid, int n, long long m){
    long long ans = 1;
    for(int i = 1; i<=n;i++){
         ans = ans * mid;
      if(ans > m) 
      return 2;
    }
      if(ans == m) return 1;
      return 0;
}
  int nthRoot(int n, long long m) {
    int low = 0, high = m;
    while(low<=high){
      int mid = low + (high - low)/2;
      int midN = func(mid, n, m);
      if(midN == 1){
        return mid;
      }
      else if(midN == 0){
         low = mid + 1;
      }
      else{
         high = mid - 1;
    }
    }
    return -1;
  }
};