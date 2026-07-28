class Solution {
   public:
    bool isValid(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
            return true;
    }

    void dfs(string &s, vector<vector<string>>& ans, vector<string>& output, int start) {
        
        if(start==s.size()){
            ans.push_back(output);
            return;
        }

        for(int end=start;end<s.size();end++){
            string temp=s.substr(start,end-start+1);

            if(isValid(temp)){
                output.push_back(temp);
                dfs(s,ans,output,end+1);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        string d = "";
        vector<string> output;

      dfs(s, ans, output, 0);
    return ans;  
    }
};
