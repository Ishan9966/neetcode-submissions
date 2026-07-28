class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;

        int l = 0;
        int maxLen = 0; 

        for (int r = 0; r < s.size(); r++) {
             hash[s[r]]++;
             while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
             }
           
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};