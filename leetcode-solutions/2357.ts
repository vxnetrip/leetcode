function minimumOperations(nums: number[]): number {

    let result: number[] = [];

    for (let num of nums) {
        if (num !== 0 && !(num in result)) {
            result.push(num);
        }
    }
    return result.length;
};




let nums: number[] = [];
let result: number = minimumOperations(nums);

console.log(result);