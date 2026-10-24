class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int n = list1.size();
        int m = list2.size();
        unordered_map<string,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[list1[i]] = i;
        }
        int minSum = INT_MAX;
        int sum = 0;
        for(int j = 0; j < m; j++){
            if(mpp.find(list2[j]) != mpp.end()){
                sum = mpp[list2[j]] + j;
                if(sum < minSum){
                    ans.clear();
                    ans.push_back(list2[j]);
                    minSum = sum;
                }
                else if(sum == minSum){
                ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};