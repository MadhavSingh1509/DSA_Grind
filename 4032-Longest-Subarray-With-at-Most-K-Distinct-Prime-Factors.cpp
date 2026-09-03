class Solution {
public:

    vector<int> getFactors(int num) {

        vector<int> factors;

        for (int p = 2; p * p <= num; p++) {

            if (num % p == 0) {

                factors.push_back(p);

                while (num % p == 0)
                    num /= p;
            }
        }

        if (num > 1)
            factors.push_back(num);

        return factors;
    }


    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        map<int, int> m;

        int i = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {

            // Add factors of nums[j]
            vector<int> factors = getFactors(nums[j]);

            for (int p : factors)
                m[p]++;


            // Shrink window
            while (m.size() > k) {

                vector<int> factors = getFactors(nums[i]);

                for (int p : factors) {

                    m[p]--;

                    if (m[p] == 0)
                        m.erase(p);
                }

                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};