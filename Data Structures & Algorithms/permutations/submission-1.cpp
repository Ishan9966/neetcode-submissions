class Solution {
   public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans,int i) {
    if(i==nums.size()){
        ans.push_back(nums);
    }
    for(int a=i;a<nums.size();a++){
        swap(nums[i],nums[a]);
        dfs(nums,ans,i+1);
        swap(nums[i],nums[a]);
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
        dfs(nums, ans,0);
        return ans;
    }
};
