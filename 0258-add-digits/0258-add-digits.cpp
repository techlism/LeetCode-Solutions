class Solution {
void add(int &num,size_t ans){
    if(num<10){
        return;
    }
    while(num>0){
        int digit=num%10;
        ans=ans+digit;
        num=num/10;
    }
    num=ans;
    ans=0;
    add(num,ans);
}
public:
    int addDigits(int num) {
        size_t ans=0;
        add(num,ans);
        return num;
        //ONE LINE ANSWER (return 1 + (num - 1) % 9;)
        //How?? See pattern for the numbers till 100
    }
};