/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let st=new Set();
    let i=0;
    let ans=0;
    for(let j=0;j<s.length;j++){
        while(st.has(s[j])){st.delete(s[i]);i++;}
        st.add(s[j]);
        ans=Math.max(ans,j-i+1);}
        return ans;
    
};