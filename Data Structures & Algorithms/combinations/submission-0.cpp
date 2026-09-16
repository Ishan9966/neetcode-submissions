class Solution {
   public:
    void f(int n, int k, int ind, vector<vector<int>>& ans, vector<int> temp) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (ind > n) return;

        temp.push_back(ind);
        f(n, k, ind + 1, ans, temp);
        temp.pop_back();
        f(n, k, ind + 1, ans, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> temp;
        f(n, k, 1, ans, temp);
        return ans;
    }
};