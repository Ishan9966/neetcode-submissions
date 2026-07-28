class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int maxi = INT_MIN;
        for (int i = 0; i < k; i++) {
            maxi = max(maxi, nums[i]);
        }
        ans.push_back(maxi);
        int l = 1, r = k;
        while (r < nums.size()) {
            maxi=INT_MIN;
            for (int i = l; i <= r; i++) {
                maxi = max(maxi, nums[i]);
            }
            ans.push_back(maxi);
            r++;
            l++;
        }
        
        return ans;
    }
};
