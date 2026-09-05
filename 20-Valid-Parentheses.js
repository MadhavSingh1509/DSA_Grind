/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let st=[];
    for(let ch of s){
        if(ch==='('||ch==='['||ch==='{')st.push(ch);
        else {
            if(st.length===0)return false;
            let top=st.pop();
            if((top==='('  && ch !=')')||(top==='{'&& ch!='}')||(top==='['&& ch!=']'))return false;
        }
    }
    return st.length===0;
};