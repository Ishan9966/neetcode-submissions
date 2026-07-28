    #include<algorithm>
    class Solution {
    public:
        bool canEat(vector<int>& piles, int x, int h) {
            int ans = 0;
            for (int i = 0; i < piles.size(); i++) {
                int hrs = (piles[i]+x-1) / x;
                ans += hrs;
            }
            if (ans <= h) {
                return true;
            }
            return false;
        }

        int minEatingSpeed(vector<int>& piles, int he) {
            int maxi = *std::max_element(piles.begin(), piles.end());
            int res = 0;
            int l = 1, h = maxi;
            while (l <= h) {
                int m = l+(h - l) / 2;
                if (canEat(piles, m, he)) {
                    h = m - 1;
                    res = m;
                } else {
                    l = m + 1;
                }
            }
            return res;
        }
    };
