class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* T.C. 0(N)
           S.C. 0(N) (Due to Stack) */
        if(nums.size()==1){
            return nums.size();
        }
        stack<int>s;
        int freq=0;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                s.push(nums[i]);
                ++freq;
                continue;
            }
            if(s.top()==nums[i]&&freq<2){
                ++freq;
                s.push(nums[i]);
            }
            if(s.top()!=nums[i]){
                s.push(nums[i]);
                freq=0;
                ++freq;
            }
        }
        nums.clear();
        while(!s.empty()){
            nums.push_back(s.top());
            s.pop();
        }
        reverse(nums.begin(),nums.end());
        return nums.size(); 
    }
};