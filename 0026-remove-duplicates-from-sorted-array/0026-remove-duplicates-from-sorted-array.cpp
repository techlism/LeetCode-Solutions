class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // stack<int>stack;
        // for(int num : nums){
        //     if(stack.empty()){
        //         stack.push(num);  
        //         continue;
        //     } 
        //     if(stack.top() != num){
        //         stack.push(num);
        //     }
        // }
        // int size = stack.size() - 1;
        // int ans = stack.size();
        // while(size >= 0){
        //     nums[size--] = stack.top();
        //     stack.pop();
        // }
    // return ans; // A good and intuitive solution but not memory efficient
        int k=1;
        for(int i=1; i<nums.size(); i++){
         if(nums[i]!=nums[i-1]){
           nums[k++] = nums[i];  
         } 
        }   
        return k;
    }
};