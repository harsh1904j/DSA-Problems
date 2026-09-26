class Solution {
        string s;
    int pos;

    set<string> parseTerm() {
        set<string> result = {""};
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            set<string> factor = parseFactor();
            set<string> merged;
            for (const string& a : result)
                for (const string& b : factor)
                    merged.insert(a + b);
            result = move(merged);
        }
        return result;
    }

    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++;
            set<string> inner = parseExpr();
            pos++;
            return inner;
        }
        int start = pos;
        while (pos < (int)s.size() && islower(s[pos])) pos++;
        return {s.substr(start, pos - start)};
    }

    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (pos < (int)s.size() && s[pos] == ',') {
            pos++;
            set<string> t = parseTerm();
            result.insert(t.begin(), t.end());
        }
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> res = parseExpr();
        return vector<string>(res.begin(), res.end());
        
    }
};