class Solution {
   public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }

   string foreignDictionary(vector<string>& words) {
    int n = words.size();

    vector<vector<int>> adj(26);
    unordered_set<int> present;
    for (auto& w : words)
        for (char c : w)
            present.insert(c - 'a');

    for (int i = 0; i < n - 1; i++) {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min((int)s1.size(), (int)s2.size());

        // edge case: s1 is longer but is a prefix of s2 reversed -> invalid order
        if (len == (int)s1.size() && len == (int)s2.size() && s1 == s2) continue;
        bool foundDiff = false;
        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                foundDiff = true;
                break;
            }
        }
        if (!foundDiff && s1.size() > s2.size()) return ""; // invalid dictionary
    }

    vector<int> topo = topoSort(26, adj);

    string ans = "";
    for (auto it : topo) {
        if (present.count(it)) ans += char(it + 'a');
    }

    // if topo didn't include all present letters, there's a cycle -> invalid
    if ((int)ans.size() != (int)present.size()) return "";

    return ans;
}
};
