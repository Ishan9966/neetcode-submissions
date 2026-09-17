class Solution {
   public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
            if (hash[s[i]] > (s.size() + 1) / 2) return "";
        }

        for (auto [key, value] : hash) {
            maxHeap.push({value, key});
        }

        string ans = "";

        while (maxHeap.size() >= 2) {
            auto p1 = maxHeap.top();
            maxHeap.pop();
            auto p2 = maxHeap.top();
            maxHeap.pop();

            ans.push_back(p1.second);
            ans.push_back(p2.second);
            p1.first--;
            p2.first--;

            if (p1.first > 0) {
                maxHeap.push(p1);
            }
            if (p2.first > 0) {
                maxHeap.push(p2);
            }
        }

        if(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
        }

        return ans;
    }
};