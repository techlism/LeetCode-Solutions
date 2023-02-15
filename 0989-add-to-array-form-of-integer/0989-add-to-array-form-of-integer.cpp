class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>num2;
        while(k>0){
            num2.push_back(k%10);
            k=k/10;
        }
        reverse(num.begin(),num.end());
        int carry=0;
        vector<int>ans;
        int n = max(num.size(),num2.size());
        for(int i=0;i<n;i++){
            if(i<num2.size() && i < num.size()){
                int sum = num[i] + num2[i] + carry;
                ans.push_back(sum%10);
                carry=sum/10;
            }
            if(i<num.size() && i>= num2.size()){
                int sum=num[i]+carry;
                ans.push_back(sum%10);
                carry=sum/10;
            }
            if(i>=num.size() && i < num2.size()){
                int sum=num2[i]+carry;
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