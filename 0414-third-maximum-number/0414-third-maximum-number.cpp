class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s;
        for(int num : nums){
            s.insert(num);
        }
        if(s.size()<=3){
            if(s.size()==1 ||s.size()==3){
                // if size==3 so the begining element will be the third maximum
                return *s.begin();
            } 
            else{
                // For Two elements the second value will be maximum
                auto itr=s.begin();
                return *(++itr);                
            }
        }
        else{
            //Size is greater than 3.So, 3rd element from last will be the answer.
            auto itr=s.end();
            --itr;
            --itr;
            --itr;
            return *itr;
        }
    }
};