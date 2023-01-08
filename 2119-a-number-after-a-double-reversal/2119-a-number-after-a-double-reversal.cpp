class Solution {
private:
    int reversed(int num){
        if(num<10){
            return num;
        }
        int digit=0;
        int ans=0;
        while(num!=0){
            digit=num%10;
            ans=ans*10 + digit;
            num=num/10;
        }
        return ans;
    }
public:
    bool isSameAfterReversals(int num) {
        int r1=reversed(num);
        int r2=reversed(r1);
        if(r2==num){
            return true;
        }
        else{
            return false;
        }
    }
};