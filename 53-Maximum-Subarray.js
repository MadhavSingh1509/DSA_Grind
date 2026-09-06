/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let currsum=nums[0];
  let ans=nums[0];
  for(let i=1;i<nums.length;i++){
    let x=nums[i];
    currsum=Math.max(x,currsum+x);
    ans=Math.max(ans,currsum);
  }
  return ans;
};