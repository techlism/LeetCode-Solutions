class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int l1=num1.length()-1;
        int l2=num2.length()-1;
        
        //Storing in reverse order.
        vector<int>res(l1+l2+2,0);
        
        for(int i=l1;i>=0;i--){
            for(int j=l2;j>=0;j--){
                
                res[i+j+1]+=(num1[i]-'0') * (num2[j]-'0');
                
                res[i+j]+=res[i+j+1]/10;
                
                res[i+j+1]%=10;
            }
        }
        int i = 0;
        string ans = "";
        //Remove the leading zeroes
        while (res[i] == 0) {
          i++;  
        }            
        while (i < res.size()){
            ans += to_string(res[i++]);
        }
        return ans;
    }
};