class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) fives++;
            if (bills[i] == 10) {
                if (fives == 0) return false;
                fives--;
                ten++;
            }
            if (bills[i] == 20) {
                if (fives >= 3)
                    fives -= 3;
                else if (fives > 0 && ten > 0) {
                    fives--;
                    ten--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};