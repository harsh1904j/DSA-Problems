class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        while(left <= right){
            int temp = left;
            int i = left;
            bool ok = true;
            while(i > 0){
                int x = i % 10;
                if(x == 0 || temp % x != 0){
                    ok = false;
                    break;
                }
                i /= 10;
            }
        if(ok) ans.push_back(temp);
        left++;
        }
        return ans;
    }
};