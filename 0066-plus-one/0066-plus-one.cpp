class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=0;
        vector<int>ans;
        for(int i=0;i<digits.size();i++){
            if(i==0){
                int sum=digits[i]+1;
                ans.push_back(sum%10);
                carry=sum/10;
            }
            else{
                int sum=digits[i]+carry;
                ans.push_back(sum%10);
                carry=sum/10;
            }
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};