class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<>> pq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};