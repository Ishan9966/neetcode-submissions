class Solution {
   public:
    bool dfs(vector<int>& matchsticks, vector<int>& dp, int idx, int target) {
        if (idx == matchsticks.size()) {
            if (dp[0] == dp[1] && dp[1] == dp[2] && dp[2] == dp[3]) return true;
            return false;
        }
        for (int i = 0; i < 4; i++) {
            if(dp[i]+matchsticks[idx]>target)continue;

            int j=i-1;
            while(j>=0){
                if(dp[i]==dp[j])break;
                j--;
            }

            if(j!=-1)continue;


            dp[i] += matchsticks[idx];
            if (dfs(matchsticks, dp, idx + 1, target)) return true;
            dp[i] -= matchsticks[idx];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() == 0) return false;
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        int target=sum/4;
        vector<int> dp(4, 0);

        return dfs(matchsticks, dp, 0,target);
    }
};