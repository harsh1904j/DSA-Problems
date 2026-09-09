class Solution {
public:
    int lengthOfLastWord(string s) {
       vector<string> words;
       string word = "";
       for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            word += s[i];
        }
        else if(!word.empty()){
            words.push_back(word);
            word = "";
        }
       }
       if(!word.empty()) words.push_back(word);
       return words[words.size()-1].size();
    }
};