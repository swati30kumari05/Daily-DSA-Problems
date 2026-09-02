class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {
        
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);

        function<bool(int)> dfs = [&](int u) {
            if (u == destination)
                return true;

            vis[u] = true;

            for (int v : adj[u]) {
                if (!vis[v] && dfs(v))
                    return true;
            }

            return false;
        };

        return dfs(source);
    }
};
