#include <bits/stdc++.h>

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int n3;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                nums.push(stoi(tokens[i]));
            } else {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                if (tokens[i] == "+") {
                    int n3 = n1 + n2;
                    nums.push(n3);
                } else if (tokens[i] == "/") {
                    int n3 = n2 / n1;
                    nums.push(n3);
                } else if (tokens[i] == "*") {
                    int n3 = n2 * n1;
                    nums.push(n3);
                } else if (tokens[i] == "-") {
                    int n3 = n2 - n1;
                    nums.push(n3);
                }
            }
        }
        return nums.top();
    }
};
