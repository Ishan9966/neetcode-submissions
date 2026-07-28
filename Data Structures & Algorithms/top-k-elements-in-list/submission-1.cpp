#include<bits/stdc++.h>

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        for (int i = 0; i < k; i++) {
            int maxi = 0;
            int maxi_key;
            for (auto const& x : hash) {
                if (maxi < x.second) {
                    maxi = max(maxi, x.second);
                    maxi_key = x.first;
                }
            }
            ans.push_back(maxi_key);
            hash.erase(maxi_key);
        }
        return ans;
    }
};
