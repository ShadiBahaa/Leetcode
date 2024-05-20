/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const ans = [];
    for (const index in arr){
        if (fn(arr[index],Number(index))){
            ans.push(arr[index]);
        }
    }
    return ans;
};