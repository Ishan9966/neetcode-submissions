class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        int u = edges.size();
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto& neighbor : adj[node]) {
                if(vis[neighbor])continue;
                vis[neighbor]=true;
                q.push(neighbor);
            }
        }
        return cnt==n;
    }
};
