class Solution {
   public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> output, int target, int i) {
        
         if (target == 0) {
            ans.push_back(output);
            return;
        }

        if (i == nums.size()){
            return;
        }
        if (target<0){
            return;
        }
        output.push_back(nums[i]);
        dfs(nums, ans, output, target-nums[i], i);
        output.pop_back();

        dfs(nums, ans, output, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        vector<int> output;
        dfs(nums, ans, output, target, 0);
        return ans;
    }
};
