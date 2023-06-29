class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans ;
        // Inorder to find triplets we are stopping our iterator two values behind
        for(int i = 0 ; i < nums.size()-2; i++){
            
            // to avoid duplicate i            
            if(i==0 || (nums[i]!=nums[i-1])){
                // sum is a and nums[hi] and nums[lo] are b and c kinda                
                int lo = i+1 , hi = nums.size()-1 , sum = 0 - nums[i] ; 
                
                while(lo<hi){
                    
                    if(nums[lo] + nums[hi] == sum) {
                    
                        ans.push_back({nums[i],nums[lo],nums[hi]});
                    
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++ ; // To avoid duplicate lo

                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;  // To avoid duplicate hi

                        lo++;

                        hi--;
                    }
                    else if( nums[lo] + nums[hi] < sum) lo ++;
                    
                    else hi-- ;
                }
            }
        }
        return ans;
    }
};