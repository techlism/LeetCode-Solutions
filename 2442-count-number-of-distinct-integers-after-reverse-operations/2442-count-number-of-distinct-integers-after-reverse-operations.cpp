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
        for(auto num : nums) {
            int rev = intRev(num);
            if(rev != num){
                unique.insert(num);
                unique.insert(intRev(num));                
            }
            else unique.insert(num);

        }
        return unique.size();
    }
};