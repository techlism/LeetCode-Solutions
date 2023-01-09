class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0){
            return 0;
        }
        int s=0;
        int e=citations.size()-1;
        int n=citations.size();
        while(s<=e){
            int mid=(s+e)>>1;
            if(citations[mid]==n-mid){
                return citations[mid];
            }
            else if(citations[mid]>n-mid){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return n-s ;
    }
};