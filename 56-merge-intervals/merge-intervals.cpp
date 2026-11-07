class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> mergeInt;
        if(n == 0) return mergeInt;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1], temp[1]);
            }
            else{
                mergeInt.push_back(temp);
                temp = intervals[i];
            }
        }
        mergeInt.push_back(temp);
        return mergeInt;
    }
};