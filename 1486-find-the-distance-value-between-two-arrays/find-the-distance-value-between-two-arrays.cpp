class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int n = arr1.size();
    int m = arr2.size();
    int cnt = 0;  
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
        bool valid = true;
        if (pos < m && abs(arr1[i] - arr2[pos]) <= d) valid = false;
        if (pos > 0 && abs(arr1[i] - arr2[pos - 1]) <= d) valid = false;
        if (valid) cnt++;
    }
    return cnt;
    }
};