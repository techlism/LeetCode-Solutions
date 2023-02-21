class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //T.C. O(N) & S.C. O(N)
        // stack<int>s;
        // s.push(nums[0]);
        // int num=INT_MIN;
        // for(int i=1;i<nums.size();i++){
        //     if(!s.empty() && s.top()==nums[i]){
        //         num=s.top();
        //         s.pop();
        //     }
        //     else{
        //         if(num!=nums[i]){
        //             s.push(nums[i]);
        //         }
        //     }
        // }
        // return s.top();
        
        //O(LOGN) & O(1) - Binary Search
        
        int s = 0, e = nums.size() - 1;
        while(s < e){
            int mid = s + (e-s)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                s = mid + 1;
            else
                e = mid;
        }
        return nums[s];
    }     
};