class Solution {
public:
    int firstUniqChar(string s) {
       int find[26] = {0};
       for(int i = 0; i < s.size();i++){
        find[s[i]-'a']++;
       }
       for(int i = 0; i < s.size(); i++){
        if(find[s[i]-'a'] == 1) return i;
       }
       return -1;
    }
};