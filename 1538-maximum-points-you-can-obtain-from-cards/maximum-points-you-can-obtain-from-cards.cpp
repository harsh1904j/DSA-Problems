class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;
        for(int i = 0; i < k; i++){
            leftSum = leftSum + arr[i];
        }
        maxSum = leftSum;
        int rindex = n-1;
        for(int i = k-1; i >= 0; i--){
            leftSum = leftSum - arr[i];
            rightSum = rightSum + arr[rindex];
            rindex--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};