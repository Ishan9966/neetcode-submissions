class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> result(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j-- ){
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int p = a * b;
                int pos = i + j;
                int pos2 = i + j + 1;
                int sum = p + result[pos2];

                result[pos2] = sum % 10;
                result[pos] += sum / 10;
            }
        }
        string ans;
        for (int digit : result) {
            if (ans.empty() && digit == 0) continue;

            ans += digit + '0';
        }

        return ans;
    }
};
