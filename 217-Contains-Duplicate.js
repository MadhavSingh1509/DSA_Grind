/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let st=new Set();
    for(let x of nums){
        if(st.has(x))return true;
        st.add(x);
    }
    return false;
};