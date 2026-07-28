class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int left=1;
        int right=1;
        for (int i = 0; i < nums.size(); i++) {
            if(left==0)left=1;
            if(right==0)right=1;

            left*=nums[i];
            right*=nums[nums.size()-i-1];
            maxi=max({maxi,left,right});
        }
        return maxi;
    }
};
