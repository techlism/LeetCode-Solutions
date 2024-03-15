class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product = 1;
        int zero_present = 0;
        for(int num : nums){
            if(num == 0) zero_present +=1;
            else product *= num;
        }
        for(int num : nums){
            if(num==0 && zero_present==1) ans.emplace_back(product);
            if(num==0 && zero_present > 1) ans.emplace_back(0);
            if(num !=0 && zero_present >= 1) ans.emplace_back(0);
            if(num !=0 && zero_present == 0) ans.emplace_back(product/num);
        }
        return ans;
    }
};