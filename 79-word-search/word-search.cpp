class Solution {
public:
    bool find(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (board[i][j] != word[k]) return false;
        char temp = board[i][j];
        board[i][j] = '$';            
        bool found = find(board, word, i + 1, j, k + 1) ||
                     find(board, word, i - 1, j, k + 1) ||
                     find(board, word, i, j + 1, k + 1) ||
                     find(board, word, i, j - 1, k + 1);
        board[i][j] = temp;           
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if (word.size() > m * n) return false;
        unordered_map<char, int> freq;
        for (auto& row : board)
            for (char c : row) freq[c]++;
        for (char c : word)
            if (--freq[c] < 0) return false;
        if (freq[word[0]] > freq[word.back()])
            reverse(word.begin(), word.end());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (find(board, word, i, j, 0)) return true;
        return false;
    }
};