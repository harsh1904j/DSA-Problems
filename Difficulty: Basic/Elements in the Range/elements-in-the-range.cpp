class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        unordered_set<int> present(arr.begin(), arr.end());
                for (int x = start; x <= end; x++) {
                if (present.find(x) == present.end())
                return false;
            }
        return true;
    }
};
