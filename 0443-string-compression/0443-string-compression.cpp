class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j=0;
        while(i<chars.size()){
            int count=1;
            while((i<chars.size()-1) && (chars[i]==chars[i+1])){
                i++;
                count++;
            }
            chars[j++]=chars[i];
            if (count!=1){
                string num="";
                while(count){
                    num+='0'+count%10;
                    count=count/10;
                }
                reverse(num.begin(),num.end());
                for(char v:num){
                    chars[j++]=v;
                }
            }
            i++;
        }
        return j;
    }
};