class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    stringstream ss(sentence);
    string word;
    string result;

    while (ss >> word) {
        string root;
        for (int i = 1; i <= word.length(); ++i) {
            root = word.substr(0, i);
            if (dict.find(root) != dict.end()) {
                break;
            }
        }
        if (!result.empty()) {
            result += " ";
        }
        result += root;
    }

    return result;
        
    }
};