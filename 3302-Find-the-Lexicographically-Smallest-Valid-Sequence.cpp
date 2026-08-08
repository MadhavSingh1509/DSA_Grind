class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> right(m + 1, 0);

        int rightmatch = 0;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0) {

            // CHANGED: while -> if
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
                rightmatch++;
            }

            right[i] = rightmatch;
            i--;
        }

        vector<int> ans;
        bool canchange = true;

        i = 0;
        j = 0;

        while (i < m && j < n) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (canchange && right[i + 1] >= n - j - 1) {
                canchange = false;
                ans.push_back(i);
                j++;
            }

            i++;
        }

        if (j < n)
            return {};

        return ans;
    }
};