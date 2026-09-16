class Solution {
   public:
    void f(vector<int>& nums, vector<int> temp, vector<bool>& used, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            temp.push_back(nums[i]);

            f(nums, temp, used, ans);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);
        vector<vector<int>> ans;
        vector<int> temp;

        f(nums, temp, used, ans);
        return ans;
    }
};