class Solution {
   public:
    string simplifyPath(string s) {
        stack<string> st;

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '/') {
                i++;
                continue;
            }

            string temp = "";
            while (i < s.size() && s[i] != '/') {
                temp += s[i];
                i++;
            }

            if (temp == ".")
                continue;

            else if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(temp);
            }
        }

        string ans="";

        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.empty())return "/";

        return ans;
    }
};