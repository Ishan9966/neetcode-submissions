class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_set<char> letters(s.begin(),s.end());
        int maxi = 0;

        for(char c:letters){
            int count=0,l=0;
            for(int r=0;r<s.size();r++){
                if(s[r]==c){
                    count++;
                }
                while((r-l+1)-count>k){
                    if(s[l]==c){
                        count--;
                    }
                    l++;
                }
            maxi=max(maxi,r-l+1);
            }
        }
        return maxi;
    }
};
