class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for (int ind = 0; ind < strs[0].size(); ind++) {
            bool allMatched = true;
            for (int j = 1; j < strs.size(); j++) {
               if (ind >= strs[j].size() || strs[j][ind] != strs[0][ind]) {
                    allMatched = false;
                    break;
                }
            }
            if (allMatched) {
                ans += strs[0][ind];
            }else{
                break;
            }
        }
        return ans;
    }
};