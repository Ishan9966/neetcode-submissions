class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1;
        int temp=cnt;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1) temp++;
            else if(nums[i]==nums[i-1]) continue;
            else temp=1;
            cnt=max(cnt,temp);
        }
        return cnt;
    }
};
