class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack < pair<int, int>> st;
        vector<int> ans(t.size(), 0);
        int n = t.size() - 1;

        st.push({t[n], n});
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && t[i] >= st.top().first) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = 0;
                st.push({t[i], i});
            } else {
                ans[i] = st.top().second - i;
                st.push({t[i], i});
            }
        }
        return ans;
    }
};
