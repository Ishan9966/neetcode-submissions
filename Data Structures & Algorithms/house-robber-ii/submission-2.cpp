class Solution {
public:

    int helper(vector<int>& nums){
         int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int notTake=0+prev;

            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;   
        }

        return prev;
    }
    int rob(vector<int>& nums) {

        int n=nums. size();
        if (n == 1)
    return nums[0];
        vector<int> n1(n-1);
        vector<int> n2(n-1);
        for(int i=0;i<n-1;i++){
            n1[i]=nums[i];
        }
        for(int i=1;i<n;i++){
            n2[i-1]=nums[i];
        }
        return max(helper(n1),helper(n2));
    }
};
