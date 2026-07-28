class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> st;
        unordered_map<char,int> tt;

        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            st[s[i]]++;
            tt[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(st[s[i]]!=tt[s[i]]) return false;
        }
        return true;
    }
};
