class Solution {
  public:
    string maxOdd(string num) {
        int ind = -1;
        for(int i = num.size()-1; i>=0; i--){
            if((num[i] - '0') % 2 == 1){
                ind = i;
                break;
            }
        }
        return num.substr(0, ind+1);
    }
};