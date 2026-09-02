class Solution {
public:
    void dfs(int u, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[u] = true;

        for (int v = 0; v < graph.size(); v++) {
            if (graph[u][v] && !vis[v])
                dfs(v, graph, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};
