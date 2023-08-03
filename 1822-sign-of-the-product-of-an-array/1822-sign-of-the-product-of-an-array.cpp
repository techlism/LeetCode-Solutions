class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto num : nums){
            if(num < 0) neg++ ;
            if(num == 0) return 0;
        }
        return neg % 2 == 0 ? 1 : -1;
        
    }
};