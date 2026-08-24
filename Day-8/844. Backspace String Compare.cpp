class Solution {
public:
    string build(string s) {
        string t;
        for (char c : s) {
            if (c == '#') {
                if (!t.empty()) t.pop_back();
            } else t += c;
        }
        return t;
    }
    
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};
