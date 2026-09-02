class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v){
        sort(v.begin(),v.end());
        vector<vector<int>> a;
        for(auto &i:v)
            if(a.empty()||a.back()[1]<i[0]) a.push_back(i);
            else a.back()[1]=max(a.back()[1],i[1]);
        return a;
    }
};
