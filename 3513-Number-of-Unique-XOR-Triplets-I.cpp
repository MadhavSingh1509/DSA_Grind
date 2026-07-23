class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 1;   // only {nums[0]}
        if(n == 2) return 2;   // {nums[0], nums[1], nums[0]^nums[1]}
        
        // next power of 2 after n is bits,=log2(n)+1;
        int bits = 32 - __builtin_clz(n);  
        // (bits is same as floor(log2(n))+1)
        return 1 << bits;  
      //  1<<bit=2 power bits
    }
};
