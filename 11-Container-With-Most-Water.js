/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let n=height.length;
    let l=0;
    let r=n-1;
    let ans=0;
    while(l<r){
        let a=(r-l)*Math.min(height[l],height[r]);
ans=Math.max(ans,a);
if(height[l]<height[r])l++;
else r--;
    }
    return ans;
};