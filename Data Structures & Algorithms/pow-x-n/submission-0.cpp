class Solution {
public:
    double myPow(double n, int x) {
        double ans = 1;
        long long exp = x;

        if(exp < 0) {
            n = 1 / n;
            exp = -exp;
        }

        while(exp > 0) {
            if(exp % 2 == 1) {
                ans *= n;
            }

            n *= n;
            exp /= 2;
        }

        return ans;
    }
};