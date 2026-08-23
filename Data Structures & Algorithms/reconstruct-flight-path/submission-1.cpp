class Solution {
public:

    unordered_map<string, multiset<string>> adj;
    vector<string> result;

    void dfs(string from) {

        while (!adj[from].empty()) {

            string to = *adj[from].begin();

            adj[from].erase(adj[from].begin());

            dfs(to);
        }

        result.push_back(from);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(result.begin(), result.end());

        return result;
    }
};