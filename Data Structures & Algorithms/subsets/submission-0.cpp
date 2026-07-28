class Solution {
   public:
    void dfs(vector<int>& nums, vector<int> output, vector<vector<int>>& ans, int i) {
        if (i >= nums.size()) {
            ans.push_back(output);
            return;
        }
        dfs(nums, output, ans, i + 1);

        int el = nums[i];
        output.push_back(el);
        dfs(nums, output, ans, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> output;
        dfs(nums, output, ans, 0);

        return ans;
    }
};
