class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s == goal) return true;
        string temp = s;
        int n = s.size();
        int i = 0;
        while(i<n){
            reverse(s.begin(), s.begin()+i);
            reverse(s.begin()+i, s.begin()+n);
            reverse(s.begin(), s.end());
            if(s == goal) return true;
            s = temp;
            i++;
        }
        return false;
    }
};