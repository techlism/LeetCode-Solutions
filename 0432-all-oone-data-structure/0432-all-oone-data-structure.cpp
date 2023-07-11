class AllOne {
private:
    unordered_map<string, int> stf;
    // Using map gives us a sorted order but increases the complexity to O(logN)
    map<int , unordered_set<string>> fts;
public:
    AllOne() {}

    void inc(string key) {
        if(stf[key] != 0){
            fts[stf[key]].erase(key);
            if (fts[stf[key]].empty()) {
                fts.erase(stf[key]);
            }
        }
        ++stf[key];
        fts[stf[key]].insert(key);
    }

    void dec(string key) {
        if (stf.find(key) == stf.end()) return;

        fts[stf[key]].erase(key);
        if (fts[stf[key]].empty()) {
            fts.erase(stf[key]);
        }

        --stf[key];
        if (stf[key] == 0) {
            stf.erase(key);
        } else {
            fts[stf[key]].insert(key);
        }
    }

    string getMaxKey() {
        if(fts.empty()) return "";
        // rbegin - basically reverse begin or last value
        else return *(fts.rbegin()->second.begin());
    }

    string getMinKey() {
        if(fts.empty()) return "";
        else return *(fts.begin()->second.begin());
    }
};
