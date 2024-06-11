class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        vector<int> remaining, result;
        // Initialize count map with relative order elements
        for (int i = 0; i < arr2.size(); i++) {
            countMap[arr2[i]] = 0;
        }
        // Count occurrences of elements in target array
        for (int i = 0; i < arr1.size(); i++) {
            if (countMap.find(arr1[i]) != countMap.end()) {
                countMap[arr1[i]]++;
            } else {
                remaining.push_back(arr1[i]);
            }
        }
        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());
        // Add elements as per relative order
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < countMap[arr2[i]]; j++) {
                result.push_back(arr2[i]);
            }
        }
        // Add remaining elements
        for (int i = 0; i < remaining.size(); i++) {
            result.push_back(remaining[i]);
        }
        return result;
    }
};