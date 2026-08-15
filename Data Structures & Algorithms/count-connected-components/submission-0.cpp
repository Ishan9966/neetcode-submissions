class Solution {
   public:
    void dfs(int ind, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[ind] = true;
        for (auto& el : adj[ind]) {
            if (!vis[el]) {
                dfs(el, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for (int i = 0; i < edges.size(); i++) {
            for (auto n : edges) {
                int u = n[0];
                int v = n[1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};
