class Solution {
   public:
    void dfs(vector<int>& nums, vector<int> &output, vector<vector<int>>& ans, int index) {
            ans.push_back(output);


        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            int el = nums[i];
            output.push_back(el);
            dfs(nums, output, ans, i + 1);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
sort(nums.begin(),nums.end());
        vector<int> output;
        dfs(nums, output, ans, 0);

        return ans;
    }
};
