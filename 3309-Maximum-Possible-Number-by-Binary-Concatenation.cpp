class Solution {
public:
    string binary(int x) {
        if (x == 0) return "0";

        string s;
        while (x) {
            s += char('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int maxGoodNumber(vector<int>& nums) {

        vector<string> v;

        for (int x : nums)
            v.push_back(binary(x));

        sort(v.begin(), v.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        string ans;

        for (auto &x : v)
            ans += x;

        int res = 0;
        for (char c : ans)
            res = res * 2 + (c - '0');

        return res;
    }
};