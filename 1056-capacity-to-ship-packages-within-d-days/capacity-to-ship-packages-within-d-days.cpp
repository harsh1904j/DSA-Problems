class Solution {
public:
int shipWithinDays(vector<int>& weight, int days) {
 int n = weight.size();
        int low = *max_element(weight.begin(), weight.end());
        int high = accumulate(weight.begin(), weight.end(), 0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int daysReq = 1, load = 0;
            for(int i = 0; i < n; i++){
                if(load + weight[i] > mid){
                    daysReq++;
                    load = weight[i];
                }
                else{
                    load += weight[i];
                }
            }
            if(daysReq <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};