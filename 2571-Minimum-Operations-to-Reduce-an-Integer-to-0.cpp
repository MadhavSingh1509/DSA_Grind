class Solution {
public:
    int minOperations(int n) {

        int ans = 0;

        while(n > 0) {

            // If n itself is a power of 2,
            // one operation is enough.
            if((n & (n - 1)) == 0) {
                ans++;
                break;
            }

            // Find the largest power of 2 <= n
            int p = 1;

            while(p * 2 <= n)
                p *= 2;

            // Distance from n to the lower power of 2
            int down = n - p;

            // Distance from n to the next power of 2
            int up = 2 * p - n;

            // Move towards whichever power of 2 is closer
            if(down <= up)
                n -= p;
            else
                n = 2 * p - n;

            ans++;
        }

        return ans;
    }
};