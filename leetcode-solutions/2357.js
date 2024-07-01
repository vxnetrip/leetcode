function minimumOperations(nums) {
    var result = [];
    for (var _i = 0, nums_1 = nums; _i < nums_1.length; _i++) {
        var num = nums_1[_i];
        if (num !== 0 && !(num in result)) {
            result.push(num);
        }
    }
    return result.length;
}
;
var nums = [];
var result = minimumOperations(nums);
console.log(result);
