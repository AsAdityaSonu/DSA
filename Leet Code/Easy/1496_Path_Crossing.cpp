#include<iostream>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int, int>> v;
        int p=0,q=0;
        v.push_back({p, q});
        int n=path.length();
        for(int i=0;i<n;i++){
            if(path[i]=='E'){
                p++;
            }else if(path[i]=='W'){
                p--;
            }else if(path[i]=='N'){
                q++;
            }else if(path[i]=='S'){
                q--;
            }

            auto it = find(v.begin(), v.end(), make_pair(p,q));
            if(it != v.end()){
                return true;
            }
            v.push_back({p, q});
        }
        return 0;
    }
};

int main()
{
    
    return 0;
}