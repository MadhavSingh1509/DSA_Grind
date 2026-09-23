class Solution {
public:
    int longestSubarrayWithTargetSum(vector<int>& arr, int target) {
    unordered_map<int, int> prefixSumMap; 
    int prefixSum = 0, maxLength = 0;

    prefixSumMap[0] = -1; 

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        
        if (prefixSumMap.find(prefixSum - target) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[prefixSum - target]);
        }

        
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }

    return maxLength;
}

// Function to find the minimum operations to reduce x to zero
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int target = totalSum - x; // The sum we need to find in a subarray

    // Edge cases
    if (target < 0) return -1; // If x is greater than totalSum, it's impossible
    if (target == 0) return n; // If the entire array sums to x, remove all elements

    int maxLength = longestSubarrayWithTargetSum(nums, target);
    
    return (maxLength == 0) ? -1 : (n - maxLength);
}
};