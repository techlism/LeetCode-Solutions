class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26]={0};
        int number=0;
        for(int i=0;i<sentence.length();i++){
            number=sentence[i]-'a';
            arr[number]++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]<1){
                return false;
            }
        }
        return true;
    }
};