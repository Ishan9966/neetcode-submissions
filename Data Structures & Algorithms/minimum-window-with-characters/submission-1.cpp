class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()){
        return "";
        } 
        string ans = "";
        int l = 0, r = 0;
        int len = INT_MAX, index = -1;
        int total = t.size();
        unordered_map<char, int> h1;
        for (int i = 0; i < t.size(); i++) {
            h1[t[i]]++;
        }
        while (r < s.size()) {
            h1[s[r]]--;
            if (h1[s[r]] >= 0) {
                total--;
            }
            while (!total) {
                if (len > r - l + 1) {
                    len = r - l + 1;
                    index = l;
                }
                h1[s[l]]++;
                if (h1[s[l]] > 0) {
                    total++;
                }
                l++;
            }
            r++;
        }
        if (index == -1) return "";

        for (int i = index; i < index + len; i++) {
            ans += s[i];
        }
        return ans;
    }
};
