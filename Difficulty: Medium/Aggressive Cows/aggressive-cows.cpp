class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int cows) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls[n-1] - stalls[0];
        while(low<=high){
            int mid = low + (high - low)/2;
            int cntCows = 1, last = stalls[0];
            for(int i = 1; i < n; i++){
                if(stalls[i] - last >= mid){
                    cntCows++;
                    last = stalls[i];
                }
            }
            if(cntCows >= cows){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};