class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;//val and freq

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto it:freq){
            if(it.second>1) return true;
        }
        return false;
    }
};