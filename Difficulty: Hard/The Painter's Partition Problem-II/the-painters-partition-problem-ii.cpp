class Solution {
  public:
    int minTime(vector<int>& boards, int k) {
        int n = boards.size();
        if(k > n) return -1;
        long long low = *max_element(boards.begin(), boards.end());
        long long high = accumulate(boards.begin(), boards.end(), 0LL);
        while(low<=high){
            long long mid = low + (high-low)/2;
            int painter = 1;
            long long painted = 0;
            for(int i = 0; i < n; i++){
                if(painted + boards[i] <= mid){
                    painted += boards[i];
                }
                else{
                    painter++;
                    painted = boards[i];
                }
            }
            if(painter > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return (int)low;
        
    }
};