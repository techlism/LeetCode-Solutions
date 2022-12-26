class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        int i=1;
        while(i<=n){
            if(i%3==0 && i%5!=0){
                ans.push_back("Fizz");
            }
            else if(i%5==0 && i%3!=0){
                ans.push_back("Buzz");
            }
            if(i%3==0 && i%5==0){
                ans.push_back("FizzBuzz");
            }
            else if(i%3!=0 && i%5!=0){
                ostringstream ostr;
                ostr << i;
                ans.push_back(ostr.str());
            }
            i++;
        }
        return ans;
    }
};