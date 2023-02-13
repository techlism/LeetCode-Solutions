class Solution {
public:
    int countOdds(int low, int high) {
        // int count = 0;
        // if(low%2==0 && high%2==0){
        //     while(low<high){
        //         count++;
        //         low=low+2;
        //     }
        // }
        // else if(low%2!=0 && high%2!=0){
        //     while(low<=high){
        //         count++;
        //         low=low+2;  
        //     }
        // }
        // else if(low%2==0 && high%2!=0){
        //     low=low+1;
        //      while(low<=high){
        //         count++;
        //         low=low+2;  
        //     }           
        // }
        // else{
        //      while(low<high){
        //         count++;
        //         low=low+2;  
        //     }            
        // }
        // return count;
        
        //One liner
        return ((high - low) >> 1) + ((low | high) & 1);        
    }
};