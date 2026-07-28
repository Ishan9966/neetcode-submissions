class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int target, int index) {
        // Base Case: Target achieved
        if (target == 0) {
            ans.push_back(output);
            return;
        }

        // Loop through candidates starting from the current index
        for (int i = index; i < nums.size(); i++) {
            // CRITICAL STEP: Skip duplicate elements at the same recursion depth
            if (i > index && nums[i] == nums[i - 1]) {
                continue; 
            }

            // Optimization: Stop if the element exceeds the remaining target
            if (nums[i] > target) {
                break; 
            }

            // Include the element and move forward
            output.push_back(nums[i]);
            dfs(nums, ans, output, target - nums[i], i + 1);
            output.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> output;

        // 1. Sort the input to group duplicates together
        sort(nums.begin(), nums.end());

        // 2. Start DFS
        dfs(nums, ans, output, target, 0);
        
        return ans;
    }
};
