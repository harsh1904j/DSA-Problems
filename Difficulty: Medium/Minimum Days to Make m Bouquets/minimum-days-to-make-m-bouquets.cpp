class Solution {
  public:
 bool possible(vector<int>& arr, int day, int k, int m){
     int n = arr.size();
     int cnt = 0, nofB = 0;
     for(int i = 0; i <= n-1; i++){
         if(arr[i] <= day){
             cnt++;
         }
         else{
             nofB += (cnt/k);
             cnt = 0;
         }
     }
     nofB += (cnt/k);
     return nofB >= m;
 }

 int minDaysBloom(vector<int>& bloomDay, int k, int m) {
          int n = bloomDay.size();
         long long pro = (long long)m * k;
         if(n < pro) return -1;
         int low = *min_element(bloomDay.begin(), bloomDay.end());
         int high = *max_element(bloomDay.begin(), bloomDay.end());
         int ans = high;
         while(low <= high){
             int mid = low + (high-low)/2;
             if(possible(bloomDay, mid, k, m) == true){
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