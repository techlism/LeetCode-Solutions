class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back()<=target){
            return letters.front();
        }
        int s=0, e=letters.size();
        char ans='a';
        int mid=s+(e-s)/2;
        while(s<=e){
            if(letters[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return letters[s];
    }
};