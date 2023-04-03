class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boats=0, start=0, end=people.size()-1 ;
        while(start <= end){
            if(people[start] + people[end] <= limit){  //Both can come in a single boat
                start++ ;
                end-- ;
            }
            else end-- ;    // Ommiting last one (being greedy)
            boats++;
        }
        return boats;        
    }
};