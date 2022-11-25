class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        for(int i=0;i<target.size();i++)
            if(arr[i]!=target[i])
                return false;
    return true;
    }
    
};