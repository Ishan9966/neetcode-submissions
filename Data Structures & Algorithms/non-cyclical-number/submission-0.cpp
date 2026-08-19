class Solution {
   public:
    int s(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum += rem * rem;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int, int> hash;
        int sum = 0;
        while (sum != 1) {
            sum = s(n);

            if (hash[sum]) {
                return false;
            } else {
                hash[sum]++;
            }

            n = sum;
        }
        return true;
    }
};
