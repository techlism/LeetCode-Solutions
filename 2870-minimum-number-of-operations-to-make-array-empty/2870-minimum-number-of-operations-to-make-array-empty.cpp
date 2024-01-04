class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto num : nums){
            freq[num]+=1;
        }
        int operations = 0;
        for(auto it : freq ){
            int f = it.second;
            if(f == 1) return -1;  
            if(f % 3 == 0) operations+=f/3;          
            else operations+=(f/3) + 1;            
        }
        return operations;
    }
};