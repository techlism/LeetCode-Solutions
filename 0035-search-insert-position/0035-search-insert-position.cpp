class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //O(N)
       //  int count=0;
       //  for(int i=0;i<nums.size();i++){
       //      if(nums[i]==target){
       //              return i;  
       //      }
       //      if(nums[i]<target){
       //          count++;
       //      }
       //    }
       // return count;
       
       //O(NLOGN)
        
        int s=0;
        int e=nums.size();
        int mid = s + (e-s)/2 ;
        while(s<e){
            if(nums[mid]>=target){
                e=mid;
            }
            else{
                s=mid+1;
            }
            cout<<nums[mid]<<endl;
            mid=s+(e-s)/2;
        }
        return s;
        
}
};