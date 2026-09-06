/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let ans=0;
    let min=Infinity;
    for(let x of prices){
        min=Math.min(x,min);
        ans=Math.max(ans,x-min);
    }
    return ans;
};