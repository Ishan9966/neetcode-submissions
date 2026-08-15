class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Empty string with patterns like a*, a*b*, a*b*c*
        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 2][0];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Normal character or '.'
                if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // '*'
                else if (p[i - 1] == '*') {

                    // Case 1: '*' matches zero occurrences
                    dp[i][j] = dp[i - 2][j];

                    // Case 2: '*' matches one or more occurrences
                    if (p[i - 2] == '.' || p[i - 2] == s[j - 1]) {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }
            }
        }

        return dp[n][m];
    }
};