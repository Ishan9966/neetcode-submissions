class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n==0) return{0};
        ans[0] = 0;
        ans[1] = 1;
        for (int i = 2; i <n+1; i++) {
            if (i % 2 != 0) {
                ans[i] = ans[i / 2] + 1;
            } else {
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};
