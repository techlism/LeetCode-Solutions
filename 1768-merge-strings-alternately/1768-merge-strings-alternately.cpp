class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans;
        int l1=word1.length(),l2=word2.length(),i=0,itr1=0,itr2=0;
        
        while(itr1<l1 || itr2<l2){            
            if(i%2==0 && itr1 < l1){
                // add first string
                ans.push_back(word1[itr1++]);
            }
            if(i%2!=0 && itr2 < l2){
                // add second string
                ans.push_back(word2[itr2++]);
            }          
            i++;
        }
        
        //check any leftover, if yes then append it at the last
        if(itr1!=l1-1){
            while(itr1<l1) ans.push_back(word1[itr1++]);
        }
        if(itr2!=l2-1){
            while(itr2<l2) ans.push_back(word2[itr2++]);
        }
        
        return ans;
    }
};