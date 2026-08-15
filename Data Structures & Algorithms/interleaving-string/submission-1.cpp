class Solution {
   public:
    int n, m, N;
    vector<vector<int>> t;
    bool solve(int i, int j, string& s1, string& s2, string& s3) {
        if (i == n && j == m) return true;
        if (i+j >= N) {
            return false;
        }
        bool result = false;

        if (t[i][j] != -1) return t[i][j];

        if (i < n && s1[i] == s3[i + j]) {
            result = solve(i + 1, j, s1, s2, s3);
        }
        if (result == true) {
            return result;
        }
        if (j < m && s2[j] == s3[i + j]) {
            result = solve(i, j + 1, s1, s2, s3);
        }
        return t[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        n = s1.size();
        m = s2.size();
        N = s3.size();
        t.assign(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, s1, s2, s3);
    }
};
