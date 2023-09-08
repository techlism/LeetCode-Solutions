class Solution {
private:
    int intRev(int num){
        string n = to_string(num);
        reverse(n.begin(),n.end());
        return stoi(n);        
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> unique;
        for(auto num : nums) unique.insert(num);
        for(auto num : nums) unique.insert(intRev(num));
        return unique.size();
    }
};