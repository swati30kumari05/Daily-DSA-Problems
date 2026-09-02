class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string x;
        
        while (ss >> x) v.push_back(x);
        
        reverse(v.begin(), v.end());
        
        string ans;
        for (string &w : v)
            ans += (ans.empty() ? "" : " ") + w;
        
        return ans;
    }
};
