#include <sstream>
class Solution {
private:
    int splitCount(string s){
        int count=0;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            count++;
        }
        return count;
    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int, greater<string> > strtowords;
        for(int i=0;i<messages.size();i++)
            strtowords[senders[i]]+=splitCount(messages[i]);
        int maxm = 0;
        string ans;
        for(auto stw : strtowords){
            if(stw.second > maxm ){
                ans=stw.first;
                maxm = stw.second;
            }
        }
        return ans;
    }
};