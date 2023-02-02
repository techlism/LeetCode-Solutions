class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()<=3){
            if(s.size()==1 ||s.size()==3){
                return *s.begin();
            } 
            else{
                auto itr=s.begin();
                return *(++itr);                
            }
        }
        else{
            auto itr=s.end();
            --itr;
            --itr;
            --itr;
            return *itr;
        }
    }
};