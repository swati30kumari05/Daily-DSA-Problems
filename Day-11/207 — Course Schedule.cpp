class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p){
        vector<vector<int>> g(n);
        vector<int> in(n);
        for(auto &e:p) g[e[1]].push_back(e[0]),in[e[0]]++;
        queue<int> q;
        for(int i=0;i<n;i++) if(!in[i]) q.push(i);
        int c=0;
        while(!q.empty()){
            int u=q.front(); q.pop(); c++;
            for(int v:g[u]) if(--in[v]==0) q.push(v);
        }
        return c==n;
    }
};
