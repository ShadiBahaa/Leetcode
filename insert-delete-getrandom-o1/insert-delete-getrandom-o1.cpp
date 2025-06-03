#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> um;
    vector<int> data;

    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (um.count(val)) return false;
        data.push_back(val);
        um[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!um.count(val)) return false;
        int ind = um[val];
        int last_val = data.back();

        swap(data[ind], data.back());
        data.pop_back();

        if (val != last_val) // Avoid unnecessary update
            um[last_val] = ind;

        um.erase(val);
        return true;
    }

    int getRandom() {
        int index = rand() % data.size();
        return data[index];
    }
};
