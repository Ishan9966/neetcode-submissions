class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        if ((hand.size() % groupSize) != 0) return false;
        map<int, int> hash;
        for (int i = 0; i < hand.size(); i++) {
            hash[hand[i]]++;
        }

        while (!hash.empty()) {
            int curr = hash.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (hash[curr + i] == 0) return false;
                hash[curr + i]--;

                if (hash[curr + i] < 1) hash.erase(curr + i);
            }
        }
        return true;
    }
};
