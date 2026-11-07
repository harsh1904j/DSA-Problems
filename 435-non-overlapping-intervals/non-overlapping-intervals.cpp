class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int, 2>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(arr.begin(), arr.end());
        int lastTime = arr[0][0];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(arr[i][1] >= lastTime){
                cnt++;
                lastTime = arr[i][0];
            }
        }
        return n - cnt;
    }
};