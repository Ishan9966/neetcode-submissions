class Solution {
public:
    bool f(int i, int j, string& p, string& s, vector<vector<int>>& dp) {

        // Both pattern and string are exhausted
        if (i < 0 && j < 0)
            return true;

        // Pattern exhausted, but string remains
        if (i < 0)
            return false;

        // String exhausted
        if (j < 0) {
            // Remaining pattern must consist of x* pairs
            if (p[i] == '*')
                return f(i - 2, j, p, s, dp);

            return false;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Normal character or '.'
        if (p[i] == '.' || p[i] == s[j]) {
            return dp[i][j] = f(i - 1, j - 1, p, s, dp);
        }

        // '*'
        if (p[i] == '*') {

            // Case 1: zero occurrences of preceding character
            bool zero = f(i - 2, j, p, s, dp);

            // Case 2: one or more occurrences
            bool multiple = false;

            if (p[i - 1] == '.' || p[i - 1] == s[j]) {
                multiple = f(i, j - 1, p, s, dp);
            }

            return dp[i][j] = zero || multiple;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, p, s, dp);
    }
};