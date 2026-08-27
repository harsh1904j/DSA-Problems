class Solution {
public:
    string removeOuterParentheses(string s) {
        string x = "";
        int cnt = 0;
        for(char ch : s){
            if(ch == '('){
                if(cnt > 0) x += ch;
                cnt++;
            }
            else{
                cnt--;
                if(cnt > 0) x += ')';
            }
        }
        return x;
    }
};