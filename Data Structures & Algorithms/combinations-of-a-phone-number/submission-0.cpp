class Solution {
   public:
    void dfs(string digits, string& output, int index, vector<string>& ans,
             unordered_map<int, string>& hash) {
        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = hash[number];
        for (int i = 0; i < value.size(); i++) {
            output.push_back(value[i]);
            dfs(digits, output, index + 1, ans, hash);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<int, string> hash;
        hash[2] = "abc";
        hash[3] = "def";
        hash[4] = "ghi";
        hash[5] = "jkl";
        hash[6] = "mno";
        hash[7] = "pqrs";
        hash[8] = "tuv";
        hash[9] = "wxyz";
        vector<string> ans;
        string output = "";

        int index = 0;
        dfs(digits, output, index, ans, hash);
        return ans;
    }
};
