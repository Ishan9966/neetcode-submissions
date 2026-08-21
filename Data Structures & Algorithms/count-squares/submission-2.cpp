class CountSquares {
   public:
    map<pair<int, int>, int> mp;
    CountSquares() {}

    void add(vector<int> point) { mp[{point[0], point[1]}]++; }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;
        for (auto& [p, freq] : mp) {
            int x2 = p.first;
            int y2 = p.second;

            if (x2 == x || y2 == y) continue;

            if (abs(x2 - x) != abs(y2 - y)) continue;

            ans += freq * mp[{x2, y}] * mp[{x, y2}];
        }
            return ans;
    }
};
