/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  let i=0,j=0;
  let n=s.length;
  let ans=0;
  let st=new Set();
  while(j<n){
    while(i<n&&st.has(s[j])){
        st.delete(s[i]);
        i++;
    }
    st.add(s[j]);
    ans=Math.max(ans,j-i+1);
    j++;
  }  
  return ans;
};