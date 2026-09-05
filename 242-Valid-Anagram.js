/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
   let a= [...s].sort().join("");
   let b= [...t].sort().join("");
    return a===b;
};