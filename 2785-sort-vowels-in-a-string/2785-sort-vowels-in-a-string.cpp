class Solution {
private:
    bool isVowel(char c) {
      c = tolower(c);
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        string vowels;
        for(auto &  ch : s){
            if(isVowel(ch)){
                vowels.push_back(ch);
                ch='0';                
            }
        }
        sort(vowels.begin(),vowels.end());
        int j = 0;
        for(auto &ch : s){
            if(ch=='0'){
                ch=vowels[j++];
            }
        }
        return s;
    }
};