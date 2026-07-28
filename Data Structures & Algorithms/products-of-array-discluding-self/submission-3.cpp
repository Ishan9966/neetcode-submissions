class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int containsZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==0){
            containsZero++;
            }else{
            product *= nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = (containsZero > 1) ? 0 : product;
            } else {
                if (containsZero) {
                    nums[i] = 0;
                } else {
                    nums[i] = product / nums[i];
                }
            }
        }
        return nums;
    }
};