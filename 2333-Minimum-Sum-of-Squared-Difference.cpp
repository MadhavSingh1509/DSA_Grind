
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(1e5 + 1, 0);

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff[d]++;
        }

        long long k = (long long)k1 + k2;

        for (int differ = 1e5; differ > 0 && k > 0; differ--) {
            int freq = diff[differ];

            if (freq == 0) continue;

            // If we can reduce every occurrence by one
            if (k >= freq) {
                diff[differ] -= freq;
                diff[differ - 1] += freq;
                k -= freq;
            } else {
                // only k occurrences can be reduced
                diff[differ] -= k;
                diff[differ - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;

        for (int differ = 0; differ <= 1e5; differ++) {
            ans += 1LL * differ * differ * diff[differ];
        }

        return ans;
    }
};
