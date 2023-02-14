// #include<string>
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry=0;
        int l1 = a.length()-1;
        int l2 = b.length()-1;
        while(l1>=0 || l2 >=0 || carry){
            int bit1=0;
            int bit2=0;
            if(l1>=0){
                bit1=a[l1--]-'0';
            }
            if(l2>=0){
                bit2=b[l2--]-'0';
            }
            int sum = bit1 + bit2 + carry;
            ans.insert(ans.begin(),sum % 2 +'0');
            carry=sum/2;
        }
        return ans;
    }
};