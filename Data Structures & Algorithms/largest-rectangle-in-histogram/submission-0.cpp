
class Solution {
   public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> ngl(h.size());
        vector<int> ngr(h.size());
        stack<int> st;

        for (int i = 0; i < h.size(); i++) {
            while(!st.empty() && h[st.top()]>h[i]){
                ngr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int i=st.top();
            ngr[i]=h.size();
            st.pop();
        }

        for(int i=h.size()-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]){
                ngl[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            ngl[st.top()]=-1;
            st.pop();
        }

        vector<int> ans(h.size(), 0);
        int maxi = INT_MIN;
        for (int i = 0; i < h.size(); i++) {
            ans[i] = h[i] * (ngr[i] - ngl[i] - 1);
            if (ans[i] > maxi) {
                maxi = ans[i];
            }
        }
        return maxi;
    }
};
