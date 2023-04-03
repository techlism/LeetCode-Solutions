/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
let numRescueBoats = function(people, limit) {
    people.sort((a,b)=>a-b);
    console.log(people);
    let boats=0;
    let start=0;
    let end = people.length - 1;
    while(start<=end){
        if(people[start] + people[end] <= limit){
            boats++;
            start++;
            end--;
        }
        else{
            end--;
            boats++;
        } 
    }
    return Number(boats);
};
