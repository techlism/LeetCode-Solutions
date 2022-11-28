class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int>s;
        s.push(nums[0]);
        int num=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(!s.empty() && s.top()==nums[i]){
                num=s.top();
                s.pop();
            }
            else{
                if(num!=nums[i]){
                    s.push(nums[i]);
                }
            }
        }
        vector<int>ans;
        ans.push_back(s.top());
        s.pop();
        ans.push_back(s.top());
        return ans;
    }
};