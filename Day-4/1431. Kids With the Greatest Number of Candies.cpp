class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& a,int e) {
        int m=*max_element(a.begin(),a.end());
        vector<bool> r;
        for(int x:a) r.push_back(x+e>=m);
        return r;
    }
};
