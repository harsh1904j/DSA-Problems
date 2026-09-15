class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> find;
        int n = magazine.size();
        for(int i = 0; i < n; i++){
            find[magazine[i]]++;
        }
        int m = ransomNote.size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(find[ransomNote[i]] > 0){
                find[ransomNote[i]]--;
                cnt++;
            }
        }
        if(cnt == m) return true;
        else return false;

    }
};