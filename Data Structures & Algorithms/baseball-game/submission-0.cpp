#include<string>
class Solution {
   public:
    int calPoints(vector<string>& s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == "+") {
                int n1 =st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int n3 = n1 + n2;

                st.push(n2);
                st.push(n1);
                st.push(n3);
            } else if (s[i] == "D") {
                int n1 = st.top();
                st.push(n1 * 2);
            } else if (s[i] == "C") {
                st.pop();
            } else {
                st.push(stoi(s[i]));
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};