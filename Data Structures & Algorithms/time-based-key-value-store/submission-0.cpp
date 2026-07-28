class TimeMap {
   private:
    vector<pair<pair<string, string>, int>> timeMap;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        timeMap.push_back({{key, value}, timestamp});
    }
    string getHelper(string key, int index, int timestamp) {
        if (index < 0) return "";

        if (timeMap[index].first.first == key && timeMap[index].second <= timestamp)
            return timeMap[index].first.second;

        return getHelper(key, index - 1, timestamp);
    }
    string get(string key, int timestamp) { return getHelper(key, timeMap.size() - 1, timestamp); }
};
