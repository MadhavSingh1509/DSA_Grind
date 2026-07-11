class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long ans = 0;
        long long num = 0;
        int sign = 1;

        for (char c : s) {

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                ans += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                ans += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                st.push(ans);
                st.push(sign);

                ans = 0;
                num = 0;
                sign = 1;
            }
            else if (c == ')') {
                ans += sign * num;
                num = 0;

                long long prevSign = st.top();
                st.pop();

                long long prevAns = st.top();
                st.pop();

                ans = prevAns + prevSign * ans;
            }
            // Ignore spaces automatically
        }

        ans += sign * num;

        return (int)ans;
    }
};