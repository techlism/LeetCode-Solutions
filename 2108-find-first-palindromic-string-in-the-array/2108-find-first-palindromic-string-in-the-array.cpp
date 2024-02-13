class Solution {
private:
    bool isPal(string word){
        int s = 0;
        int e = word.length()-1;
        while(s <= e){
            if(word[s++] != word[e--] ) return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto word : words){
            if(isPal(word)) return word;
        }
        return "";
    }
};