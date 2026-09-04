class Solution {
public:

    // int gcd(int a, int b) {
    //     if (b == 0) return a;
    //     return gcd(b, a % b);
    // }

    int calc(vector<int>& arr) {

        int n = arr.size();

        vector<int> pre(n);
        vector<int> suf(n);

    
        pre[0] = arr[0];

        for (int i = 1; i < n; i++) {
            pre[i] = gcd(pre[i - 1], arr[i]);
        }

        
        suf[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = gcd(suf[i + 1], arr[i]);
        }

        int ans = 0;


        for (int i = 0; i < n - 1; i++) {

            if (pre[i] == suf[i + 1]) {
                ans++;
            }
        }

        return ans;
    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        
        for (int del = -1; del < n; del++) {

            vector<int> arr;

            for (int i = 0; i < n; i++) {

                if (i != del) {
                    arr.push_back(nums[i]);
                }
            }

            ans = max(ans, calc(arr));
        }

        return ans;
    }
};