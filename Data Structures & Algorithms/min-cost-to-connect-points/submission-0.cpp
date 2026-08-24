class Solution {
   public:
    int primsAlgo(vector<vector<pair<int, int>>>& adj, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<bool> inMst(n, false);
        int sum = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;
            if (inMst[node] == true) continue;
            inMst[node] = true;
            sum += wt;

            for (auto& t : adj[node]) {
                int ne = t.first;
                int w = t.second;

                if (inMst[ne] == false) {
                    pq.push({w, ne});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>(2, {0, 0}));
        int mini = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return primsAlgo(adj, n);
    }
};
