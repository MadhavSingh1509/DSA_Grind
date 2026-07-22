class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> st(words.begin(), words.end());

        int maxlen = 0;
        string ans = "";

        for (auto w : words) {
            bool ok = true;
            string cur = w;

            // Check all prefixes except the empty string
            while (cur.size() > 1) {
                cur.pop_back();
                if (!st.count(cur)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (w.size() > maxlen) {
                    maxlen = w.size();
                    ans = w;
                }
                else if (w.size() == maxlen && w < ans) {
                    ans = w;
                }
            }
        }

        return ans;










    }
};