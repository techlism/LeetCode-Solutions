class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* T.C. 0(N) - Traversal 
           S.C. 0(N) (Due to Stack) */
        if(nums.size()==1){
            return 1;
        }
        stack<int>s;
        int freq=0;
        for(int num : nums){
            if(s.empty()){
                s.push(num);
                ++freq;
                continue;
            }
            if(s.top()==num && freq<2){
                ++freq;
                s.push(num);
            }
            if(s.top()!=num){
                s.push(num);
                freq=1;
            }
        }
        vector<int> dummy(0);
        nums=dummy;
        while(!s.empty()){
            //Insert at start
            nums.insert(nums.begin(),s.top());
            s.pop();
        }
        return nums.size(); 
    }
};