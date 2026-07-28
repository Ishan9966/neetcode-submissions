class Solution {
public:
    
    void dfs(int n,vector<string>& ans, int open,int close,string output){
        if(open<close){
            return;
        }

        if(open == close && open==n){
            ans.push_back(output);
            return;
        }

        if(open<n){
            dfs(n,ans,open+1,close,output+"(");
        }

        if(close<open){
            dfs(n,ans,open,close+1,output+")");
        }

    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=0;
        int close=0;
        string output="";
        dfs(n,ans,0,0,output);
        return ans;
    }
};
