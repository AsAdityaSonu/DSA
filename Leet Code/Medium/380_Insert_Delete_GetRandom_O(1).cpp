#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> mp; 

    RandomizedSet() {

    }
    
    bool search(int val){
        if(mp.find(val)!=mp.end()){
            return 1;
        }else{
            return 0;
        }
    } 

    bool insert(int val) {
        if(search(val))
            return 0;

        v.push_back(val);
        mp[val]=v.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        if(!search(val))
            return 0;

        auto it = mp.find(val);
        int lastVal = v.back();
        v[it->second] = lastVal;
        mp[lastVal] = it->second;
        v.pop_back();
        mp.erase(val);
        return 1;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    
    return 0;
}