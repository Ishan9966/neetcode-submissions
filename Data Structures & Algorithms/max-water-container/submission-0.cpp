class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int maxi=INT_MIN;
        while(l<r){
          int area=(r-l)*min(heights[l],heights[r]);
          if(heights[l]>heights[r]){
            r--;
          }else if(heights[l]<heights[r]){
            l++;
          }else{
            r--;
            l++;
          }
          maxi=max(maxi,area);
        }
        return maxi;
    }
};
