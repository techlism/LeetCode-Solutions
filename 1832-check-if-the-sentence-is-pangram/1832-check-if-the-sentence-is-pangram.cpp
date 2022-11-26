class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26]={0};
        for(int i=0;i<sentence.length();i++){
            char ch= sentence[i];
            int number=0;
            number=ch-'a';
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