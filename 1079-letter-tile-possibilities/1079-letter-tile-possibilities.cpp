class Solution {
private:
    void countPossible(string & tiles, string curr, unordered_map<int,int> &flag , unordered_set<string> &possible){
        for(int i=0;i<tiles.size();i++){
            if(flag[i]!=1){
                curr.push_back(tiles[i]);
                flag[i]=1;
                possible.insert(curr);
                countPossible(tiles,curr,flag,possible);
                curr.pop_back();
                flag[i]=0;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> possible;
        unordered_map<int,int> flag;
        countPossible(tiles,"",flag,possible);
        return (int) possible.size();
    }
};