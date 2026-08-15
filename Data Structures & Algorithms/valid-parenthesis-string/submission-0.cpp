class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum possible unmatched '('
        int high = 0; // Maximum possible unmatched '('

        for (char c : s) {
            if (c == '(') {
                low++;    // An unmatched '(' is added
                high++;   // It increases the maximum unmatched '('
            } else if (c == ')') {
                if (low > 0) low--;  // A ')' closes an unmatched '('
                high--;              // A ')' decreases the maximum unmatched '('
            } else { // c == '*'
                if (low > 0) low--;  // '*' can act as ')', reducing unmatched '('
                high++;              // '*' can act as '(', increasing unmatched '('
            }

            if (high < 0) {
                // If `high` becomes negative, it means there are more `)` than possible `(` and `*`.
                return false;
            }
        }

        // If `low` is greater than 0, it means there are unmatched `(` that cannot be balanced by `*`.
        return low == 0;
    }
};