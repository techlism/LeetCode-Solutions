class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=0;
        vector<int>ans;
        for(int i=0;i<digits.size();i++){
            int sum=0;
            if(i==0){
              sum=digits[i]+1;

            }
            else{
                sum=digits[i]+carry;
            }
            ans.insert(ans.begin(),sum%10);
            carry=sum/10;
        }
        if(carry){
            ans.insert(ans.begin(),carry);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};