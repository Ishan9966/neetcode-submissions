class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int x=0;
      int y=0;
      int n=nums.size();
      for(int i=0;i<n+1;i++){
        x^=i;
      }  
      for(int i=0;i<nums.size();i++){
        y^=nums[i];
      }  
      return x^y;
    }
};
