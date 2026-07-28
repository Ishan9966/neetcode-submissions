class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        vector<int> ans(height.size());
         int n=height.size();
        maxLeft[0]=0;
        maxRight[n-1]=0;
        for(int i=1;i<height.size();i++){
            maxLeft[i]=max(maxLeft[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],height[i+1]);
        }
        for(int i=0;i<n;i++){
            int mini=min(maxLeft[i],maxRight[i]);
            if(mini>height[i]){
                ans[i]=mini-height[i];
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};
