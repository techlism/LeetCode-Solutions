class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums[0]==target || nums[nums.size()-1]==target){
            return true;            
        }
        int n=nums.size();
        int s=0,e=n-1;
        while(s+1< n && nums[s]==nums[s+1]){
            s++;
        }
        //IF Every Element is Same
        if(s==e-1){
            if(nums[s]==target){
                return true;
            }
            else{
                return false;
            }
        }
        //If last element is equal to first element
        while(e>=0 && nums[e]==nums[0]){
            e--;
        }
        //Basically we did this(above) to avoid duplicates in first and last positions
        int start=s;
        int end=e;
        //Finding the pivot element
        int pivot = -1;
        while(s<=e){
            //Initializing mid inside the loop helps in avoiding mid updation
            int mid=s + (e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                pivot=mid;
                e=mid-1;
            }
        }
        //No pivot (Set to Original Start and End)
        if(pivot==-1){
            s=start;
            e=end;
        }
        else{
        //Updating search window according to our requirements    
         if(target>nums[end]){
            s=start;
            e=pivot-1;
         }
         else{
            s=pivot;
            e=end;
         }            
        }

     //Binary Search
    while(s<=e){
        int mid = s + (e-s)/2;
        if(nums[mid]>target){
            e=mid-1;
        }
        else if(nums[mid]<target){
            s=mid+1;
        }
        else{
            return true;
        }
    }
        return false;
    }
};