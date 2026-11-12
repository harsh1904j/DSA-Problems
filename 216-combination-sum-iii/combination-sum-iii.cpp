class Solution {
public:
        vector<vector<int>> result;
        vector<int> current;

        void solve(int s, int k, int n){
            if(current.size() == k){
                if(n == 0) result.push_back(current);
                return;
            }
            for(int i = s; i <= 9; i++){
                if(i > n) break;
                
                current.push_back(i);
                solve(i+1, k, n-i);
                current.pop_back();
            }
        }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k , n);
        return result;
    }
};