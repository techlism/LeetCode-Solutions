class RandomizedCollection {
    unordered_map<int, unordered_set<int>> map;
    vector<int>nums;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool present=true;
        if(map.find(val) == map.end()) present=false;
        nums.push_back(val);
        map[val].insert(nums.size()-1);
        return !present;
    }
    
    bool remove(int val) {
    // not present
    if(map.find(val)==map.end() || map[val].empty() ){
        return false;
    }
    else{           
        auto first = map[val].begin();
        int firstindex = *(first);
        map[val].erase(firstindex);
        if (map[val].empty()) {
            map.erase(val);
        }
        if (firstindex != nums.size() - 1) {
            nums[firstindex]=nums.back(); // swapping the values
            int back = nums.back();
            map[back].erase(nums.size()-1);
            map[back].insert(firstindex);
        }
        nums.pop_back();
    }
    return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
// \U0001f446 First Solution

// class RandomizedCollection {
//     unordered_map<int, vector<int>> map;
//     vector<int> nums;
// public:
//     RandomizedCollection() {
        
//     }
    
//     bool insert(int val) {
//         bool present = true;
//         if (map.find(val) == map.end()) present = false;
//         nums.push_back(val);
//         map[val].push_back(nums.size() - 1);
//         return !present;
//     }
    
//     bool remove(int val) {
//         // not present
//         if (map.find(val) == map.end() || map[val].empty()) {
//             return false;
//         }
//         else {
//             int firstindex = map[val].back();
//             map[val].pop_back();
//             if (map[val].empty()) {
//                 map.erase(val);
//             }
//             if (firstindex != nums.size() - 1) {
//                 nums[firstindex] = nums.back(); // swapping the values
//                 int back = nums.back();
//                 auto it = find(map[back].begin(), map[back].end(), nums.size() - 1);
//                 *it = firstindex;
//             }
//             nums.pop_back();
//         }
//         return true;
//     }
    
//     int getRandom() {
//         return nums[rand() % nums.size()];
//     }
// };
// \U0001f446 Second solution not real O(1)
