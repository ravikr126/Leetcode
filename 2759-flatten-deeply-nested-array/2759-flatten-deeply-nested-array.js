/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
     if(n<=0){
        return arr;
    }
    return arr.flat(n);
};