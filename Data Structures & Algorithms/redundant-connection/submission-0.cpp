class Solution {
   public:
    bool dfs(vector<vector<int>>& adj, int u, int v, vector<bool>& vis) {
        if (u == v) return true;
        vis[u] = true;

        for (const int& ngbr : adj[u]) {
            if (vis[ngbr]) continue;

            if (dfs(adj, ngbr, v, vis)) {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n+1);
        for (auto& edge : edges) {
            vector<bool> vis(n + 1, false);
            int u = edge[0];
            int v = edge[1];

            if (!adj[u].empty() && !adj[v].empty() && dfs(adj, u, v, vis)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
