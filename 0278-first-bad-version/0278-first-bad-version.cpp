// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //O(N) 
    //     int num=1;
    //     while(!isBadVersion(num) && num<=n)
    //         num++;
    // return num;
    /*----------------*/
        //O(LogN)
        int start=0, end=n;
        while(end-start>1){
            int mid=start+(end-start)/2;
            if(isBadVersion(mid))  
                end=mid;
            else  
                start=mid;
        }
        return end;
    }
};