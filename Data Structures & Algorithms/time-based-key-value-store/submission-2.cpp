class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>> &v = mp[key];

        int l = 0;
        int h = v.size() - 1;
        string ans = "";

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (v[m].first <= timestamp) {
                ans = v[m].second;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
};