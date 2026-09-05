/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a,b)=>a-b);
    let ans=[];
    let n=nums.length;
    for(let i=0;i<=n-3;i++){
        //skipping duplicate is
        if(i>0  &&nums[i]===nums[i-1])continue;
        let l=i+1;
        let r=n-1;
        while(l<r){
            let sum=nums[i]+nums[l]+nums[r];
            if(sum===0){
                ans.push([nums[i],nums[l],nums[r]]);
                //skipping duplicate l
                while(l<r && nums[l]===nums[l+1])l++;
                //skipping duplicates r
                while(l<r&& nums[r]===nums[r-1])r--;
                l++;r--;
            }
            else if(sum<0)l++;
           else r--;
        }

    }
    return ans;
};