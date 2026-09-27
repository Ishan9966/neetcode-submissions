#include <algorithm>
#include <cmath>

class Solution {
public:
    int integerBreak(int n) {
        // Base cases for n = 2 and n = 3 as required by problem constraints (k >= 2)
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        
        // Multiply by the remaining part (which will be 2, 3, or 4)
        return product * n;
    }
};
