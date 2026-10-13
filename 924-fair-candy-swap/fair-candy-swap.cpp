class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A , vector<int>& B) {
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);
    int diff = (sumB - sumA) / 2;
    sort(B.begin(), B.end());
    for (int i = 0; i < A.size(); i++) {
        int target = A[i] + diff;
        int low = 0, high = B.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(B[mid] == target) return{A[i], target};
            else if(B[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
    }
    return {};
    }
};