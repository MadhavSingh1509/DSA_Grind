class Solution {
public:
    int calculate(string s) {
        long long ans = 0;
        long long lastNum = 0;
        long long num = 0;
        char op = '+';

        for (int i = 0; i <= s.size(); i++) {

            if (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if (i == s.size() || (!isdigit(s[i]) && s[i] != ' ')) {

                if (op == '+') {
                    ans += lastNum;
                    lastNum = num;
                }
                else if (op == '-') {
                    ans += lastNum;
                    lastNum = -num;
                }
                else if (op == '*') {
                    lastNum *= num;
                }
                else if (op == '/') {
                    lastNum /= num;
                }

                if (i < s.size())
                    op = s[i];

                num = 0;
            }
        }

        return ans + lastNum;
    }
};