class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        vector<vector<pair<int, int>>> adj(N + 1);

        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist(N + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, k});

        while (!minHeap.empty()) {
            int currDist = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();
            if (currDist > dist[currNode]) continue;
            for (auto& neighbor : adj[currNode]) {
                int n = neighbor.first;
                int edgeWeight = neighbor.second;

                int newDist = currDist + edgeWeight;

                if (newDist < dist[n]) {
                    dist[n] = newDist;
                    minHeap.push({newDist, n});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<dist.size();i++){
if(dist[i]==INT_MAX)return -1;
maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};
