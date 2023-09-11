class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>sizeToPerson;
        for(int i=0;i<groupSizes.size();i++){
            sizeToPerson[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto itr : sizeToPerson){
            if(itr.first == itr.second.size()) ans.emplace_back(itr.second);
            else if(itr.first < itr.second.size()){
                int s = 0;
                int e = itr.first;
                while(e <= itr.second.size()){
                    vector<int> temp;
                    for(int i=s;i<e;i++) temp.emplace_back(itr.second[i]);
                    ans.emplace_back(temp);
                    s=e;
                    e+=itr.first;
                }
            }
        }
        return ans;
//         vector<vector<int>> ans;
//         unordered_map<int, vector<int>> groups;
        
//         for (int i = 0; i < groupSizes.size(); ++i) {
//             groups[groupSizes[i]].push_back(i);
//             if (groups[groupSizes[i]].size() == groupSizes[i]) {
//                 ans.push_back({});
//                 swap(ans.back(), groups[groupSizes[i]]);
//             }
//         }
        
//         return ans;        
    }
}; 