class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (char c : t)
            if (j < s.size() && s[j] == c) j++;
        return j == s.size();
    }
};
