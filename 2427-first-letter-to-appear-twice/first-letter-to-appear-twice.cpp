class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        int find[26] = {0};
        for(int i = 0; i < n; i++){
            find[s[i]-'a']++;
            if(find[s[i]-'a'] == 2){
                return s[i];
            }
        }
        return 0;
    }
};