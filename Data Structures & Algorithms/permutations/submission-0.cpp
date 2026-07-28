class Solution {
   public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds,
             unordered_map<int, bool> hash) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!hash[i]) {
                hash[i] = true;
                ds.push_back(nums[i]);
                dfs(nums,ans,ds,hash);
                ds.pop_back();
                hash[i]=false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,bool> hash;
        vector<int> ds;
        dfs(nums, ans, ds, hash);
        return ans;
    }
};
