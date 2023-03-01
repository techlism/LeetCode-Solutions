class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        if(nums.size()==1){
            return {0};
        }
        vector<int>leftsum;
        vector<int>rightsum;
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            leftsum.push_back(lsum);
            lsum=lsum+nums[i];
        }
        int rsum = 0;
        for(int i=nums.size()-1;i>=0;i--){
            rightsum.push_back(rsum);
            rsum=rsum+nums[i];
        }
        reverse(rightsum.begin(),rightsum.end());
        for(int i=0;i<leftsum.size();i++){
            leftsum[i]=abs(leftsum[i]-rightsum[i]);
        }
        return leftsum;
    }
};