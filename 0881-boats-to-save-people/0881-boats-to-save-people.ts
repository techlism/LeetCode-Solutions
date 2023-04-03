function numRescueBoats(people: number[], limit: number): number {
    people.sort((a,b)=>a-b);
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