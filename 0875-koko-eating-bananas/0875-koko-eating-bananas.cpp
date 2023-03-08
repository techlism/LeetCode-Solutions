class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        while(s<=e){
            int mid = s + (e-s)/2;
            size_t hours=0;
            for(auto p: piles){
                hours=hours+(p+mid-1)/mid;
            }
            if(hours>h){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s;
    }
};