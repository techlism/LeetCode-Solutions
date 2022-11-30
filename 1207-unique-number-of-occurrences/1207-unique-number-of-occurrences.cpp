class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size()==2 && arr[0]!=arr[1]){
            return false;
        }
        sort(arr.begin(),arr.end());
        vector<int>occ;
        int count=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                count++;
            }
            else{
                occ.push_back(count);
                count=0;
            }
        }
        for(int i=0;i<occ.size();i++){
            for(int j=i+1;j<occ.size();j++){
                if(occ[i]==occ[j])
                    return false;
            }
        }
        return true;  
    }
};