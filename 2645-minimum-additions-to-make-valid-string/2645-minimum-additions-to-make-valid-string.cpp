class Solution {
public:
    int addMinimum(string word) {
        // int freqA=0;
        // int freqB=0;
        // int freqC=0;
        // for(char c:word){
        //     if(c=='a') freqA++;
        //     if(c=='b') freqB++;
        //     if(c=='c') freqC++;
        // }
        // int maxValid = max({freqA,freqB,freqC}) * 3;
        // return maxValid - (freqA+freqB+freqC);
        //My approach was right but not greedy enough
    int ans = 0, i = 0;
    while(i < word.size()){
        (word[i] == 'a') ? i++ : ans++;     
        (word[i] == 'b') ? i++ : ans++; 
        (word[i] == 'c') ? i++ : ans++;      
    }
    return ans;
        
    }
};