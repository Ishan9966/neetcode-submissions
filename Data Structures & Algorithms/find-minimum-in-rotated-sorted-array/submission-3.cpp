class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;

        int ans = nums[0];
        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[0] <= nums[m]) {
                l = m + 1;
            } else {
                ans=nums[m];
                h = m - 1;
            }
        }
        return ans;
    }
};
