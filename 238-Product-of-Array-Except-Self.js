/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let n=nums.length;
    let prefix=new Array(n).fill(1);
    let suffix=new Array(n).fill(1);
    let ans=new Array(n).fill(1);
    for(let i=1;i<n;i++)prefix[i]=nums[i-1]*prefix[i-1];
    for(let j=n-2;j>=0;j--)suffix[j]=nums[j+1]*suffix[j+1];
    for(let i=0;i<n;i++)ans[i]=prefix[i]*suffix[i];
    return ans;

};