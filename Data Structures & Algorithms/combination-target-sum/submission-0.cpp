class Solution {
public:
    void dfs(const vector<int>& nums, int target, int idx,
             vector<int>& cur, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        if (target < 0)
            return;

        if (idx == nums.size())
            return;

        // Take current element
        cur.push_back(nums[idx]);
        dfs(nums, target - nums[idx], idx, cur, ans);
        cur.pop_back();

        // Skip current element
        dfs(nums, target, idx + 1, cur, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
};