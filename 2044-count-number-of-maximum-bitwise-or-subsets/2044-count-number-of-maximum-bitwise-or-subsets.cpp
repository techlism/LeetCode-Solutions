class Solution {
private:
    void countOr(vector<int> &nums, int curr, int index,
                 int &maxm, int &count){        
        if(index >= nums.size()) {
            if (curr > maxm){
                count=1;
                maxm=curr;
            }
            else if(curr == maxm) count+=1;
            return;
        }
        countOr(nums,curr,index+1,maxm,count);
        curr |= nums[index];
        countOr(nums,curr,index+1,maxm,count);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxm = INT_MIN;
        int curr = 1;
        countOr(nums,0,0,maxm,curr);
        return curr;
    }
};