class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Answer
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0){
            return mergedIntervals;
        }
        sort(intervals.begin(),intervals.end());
        //temporary interval
        vector<int> oneInterval=intervals[0];
        //learn more
        for(auto itr : intervals){
            //Checking if first element of i-th interval is less than / equal to oneInterval's second element
            if(itr[0] <= oneInterval[1]){
                oneInterval[1]=max(itr[1],oneInterval[1]);
            }
            else{
                mergedIntervals.emplace_back(oneInterval);
                oneInterval=itr;
            }
        }
        //If one last interval is left
        mergedIntervals.emplace_back(oneInterval);
        return mergedIntervals;
    }
};