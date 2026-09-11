class Solution {
public:
    int ans = 0;

    void solve(int pos, vector<int>& freq) {
        if (pos == 3) {
            ans++;
            return;
        }

        for (int d = 0; d <= 9; d++) {

            // first digit cannot be 0
            if (pos == 0 && d == 0)
                continue;

            // last digit must be even
            if (pos == 2 && d % 2 != 0)
                continue;

            // digit not available
            if (freq[d] == 0)
                continue;

            freq[d]--;
            solve(pos + 1, freq);
            freq[d]++;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits)
            freq[d]++;

        solve(0, freq);

        return ans;
    }
};