#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hash.find(diff) != hash.end()) {
                return {hash[diff], i}; // found the pair
            }
            hash[nums[i]] = i; // store index of current number
        }
        return {}; // if no solution
    }
};
