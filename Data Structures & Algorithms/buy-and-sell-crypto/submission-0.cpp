class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit=0;
        int buy=nums[0];
        int sell=nums[1];
        int i=0,j=1;
        while((i<nums.size() && j<nums.size())){
            buy=min(buy,nums[i]);
            sell=max(buy,nums[j]);
            if(i<j) profit=max(profit,sell-buy);
            i++;
            j++;
        }
        return profit;
    }
};
