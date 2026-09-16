class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> find;
        for(int i = 0; i < n; i++){
            find[arr[i]]++;
        }
        for(int i = 0; i < n; i++){
            if (arr[i] == 0) {
               if (find[0] >= 2) return true;
            }
            else if(find.count(2*arr[i])) return true;
        }
        return false;
    }
};