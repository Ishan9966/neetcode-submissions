class Solution {
   public:
    int trap(vector<int>& h) {
        int largest = h[0];
        int maxLeft = 0, maxRight = 0, index = 0;
        int water = 0;
        for (int i = 0; i < h.size(); i++) {
            if (largest < h[i]) {
                largest = max(h[i], largest);
                index = i;
            }
        }
        for (int i = 0; i < index; i++) {
            if (maxLeft > h[i]) {
                water += maxLeft - h[i];
            } else {
                maxLeft = h[i];
            }
        }
        for (int i = h.size() - 1; i > index; i--) {
            if (maxRight > h[i]) {
                water += maxRight - h[i];
            } else {
                maxRight = h[i];
            }
        }
        return water;
    }
};
