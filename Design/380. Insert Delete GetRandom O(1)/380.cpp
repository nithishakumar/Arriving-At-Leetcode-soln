#include<iostream>
#include<vector>
#include<unordered_map>

class RandomizedSet {
public:
    // O(n) memory
    unordered_map<int, int> vals;
    vector<int> elts;
    RandomizedSet() {

    }
    // O(1) time
    bool insert(int val) {
        if (vals.find(val) == vals.end()) {
            vals.insert({ val, elts.size() });
            elts.push_back(val);
            return true;
        }
        return false;
    }
    // O(1) time
    bool remove(int val) {
        if (vals.find(val) != vals.end()) {
            elts[vals[val]] = elts.back();
            vals[elts.back()] = vals[val];
            elts.pop_back();
            vals.erase(val);
            return true;
        }
        return false;
    }
    // O(1) time
    int getRandom() {
        int idx = rand() % elts.size();
        return elts[idx];
    }
};