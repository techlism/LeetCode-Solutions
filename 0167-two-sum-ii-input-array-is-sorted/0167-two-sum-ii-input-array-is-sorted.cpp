class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    //Two Pointer Approach
    //Time Complexity O(n)
	int s = 0;
	int e = numbers.size() - 1;
	while (s < e) {
		if (numbers[s] + numbers[e] == target){
			vector<int> res{ s + 1,e + 1 };
			return res;
		}
		else if (numbers[s] + numbers[e] > target){
			e--;
		}
		else{
			s++;
		}
	}
    //No Matching Pair
	return {};        
    }
};