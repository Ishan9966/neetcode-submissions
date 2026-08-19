class Solution {
public:
    int s(int n) {
        int sum = 0;

        while (n > 0) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> hash;

        while (n != 1) {
            if (hash.count(n))
                return false;

            hash.insert(n);
            n = s(n);
        }

        return true;
    }
};