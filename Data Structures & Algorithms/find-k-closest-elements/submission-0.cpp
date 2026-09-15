class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        int l = 0, r = arr.size() - k;
        while (l < r) {
            int m = l + (r - l) / 2;

            if (x - arr[m] > arr[m + k] - x) {
                l = m + 1; // arr[mid + k] is closer, shift window right
            } else {
                r = m;    // arr[mid] is closer or equal, keep/shift window left
            }
        }
        return std::vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};