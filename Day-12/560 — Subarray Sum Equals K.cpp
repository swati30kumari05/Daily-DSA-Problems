class Solution {
public:
    int subarraySum(vector<int>& a,int k){
        unordered_map<int,int> mp;
        mp[0]=1;
        int s=0,ans=0;
        for(int x:a){
            s+=x;
            ans+=mp[s-k];
            mp[s]++;
        }
        return ans;
    }
};
