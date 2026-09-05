class Solution {
  public:
    bool checkDuplicates(vector<int> &nums) {
       int n = nums.size();
               unordered_map<int, int> find;
               for(int i = 0; i < n; i++){
                   find[nums[i]]++;
                   if(find[nums[i]] >= 2) return true;
               }
               return false;
        
    }
};
