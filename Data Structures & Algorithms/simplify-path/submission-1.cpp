class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;

        int i = 1;

        while (i < s.size()) {
            // Skip consecutive '/'
            if (s[i] == '/') {
                i++;
                continue;
            }

            // Extract one directory/component
            string temp = "";

            while (i < s.size() && s[i] != '/') {
                temp += s[i];
                i++;
            }

            // Current directory
            if (temp == ".") {
                continue;
            }

            // Parent directory
            else if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            // Normal directory
            else {
                st.push(temp);
            }
        }

        // Build answer
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans.empty()) {
            return "/";
        }

        return ans;
    }
};