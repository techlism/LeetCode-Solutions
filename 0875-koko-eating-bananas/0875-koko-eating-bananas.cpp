class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        while(s<=e){
            int mid = s + (e-s)/2;
            //size_t to avoid integer overflow
            size_t hours=0;
            //checking for our each value in piles vector
            for(auto p: piles){
                hours += (p + mid - 1) / mid;
            }
            //The time we chose was not sufficient
            if(hours>h){
                s=mid+1;
            }
            //there could be some smaller values
            else{
                e=mid-1;
            }
        }
        return e+1;
    }
};