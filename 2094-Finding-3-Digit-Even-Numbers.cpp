class Solution {
public:
    set<int> st;

    void f(int i, vector<int>& freq, int num) {
        if (i == 3) {
            st.insert(num);
            return;
        }

        for (int x = 0; x <= 9; x++) {

            // First digit cannot be 0
            if (i == 0 && x == 0)
                continue;

            // Digit not available
            if (freq[x] == 0)
                continue;

            // Last digit must be even
            if (i == 2 && x % 2 != 0)
                continue;

            // Choose
            freq[x]--;
            f(i + 1, freq, num * 10 + x);

            // Undo
            freq[x]++;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int x : digits)
            freq[x]++;

        f(0, freq, 0);

        vector<int> ans;

        for (auto x : st)
            ans.push_back(x);

        return ans;
    }
};