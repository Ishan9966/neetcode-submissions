class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sp;
        for (int i = 0; i < speed.size(); i++) {
            sp.push_back({position[i], speed[i]});
        }
        sort(sp.begin(), sp.end());
        int n = sp.size() - 1;
        int ans = 0;
        double maxTime = 0;
        vector<double> time(n + 1);
        for (int i = n; i >= 0; i--) {
            time[i] = (double)(target - sp[i].first) / sp[i].second;
        }
        for (int i = n; i >= 0; i--) {
            if (time[i] > maxTime) {
                ans++;
                maxTime = time[i];
            }
        }
        return ans;
    }
};
