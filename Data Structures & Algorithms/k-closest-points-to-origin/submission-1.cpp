class Solution {
   public:
    int dist(int x, int y) { return x*x + y*y; }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() == 0) return {};
        priority_queue < pair<int, int>> pq;
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            int d = dist(points[i][0], points[i][1]);
            pq.push({d, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            int ind = pq.top().second;
            pq.pop();
            ans.push_back(points[ind]);
        }
        return ans;
    }
};
