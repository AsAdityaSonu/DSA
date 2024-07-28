#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph(n);

        for(auto e:edges){
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }

        auto getNeighbour = [&](int source) ->int{
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>  q;

            q.emplace(0, source);
            set<int> visited;

            while(!q.empty()){
                auto [disNode, curr]=q.top();
                q.pop();
                if(!visited.count(curr)){
                    visited.insert(curr);
                    for(auto &[neighbor, distance]: graph[curr]){
                        int distanceFromSource = disNode + distance;
                        if(distanceFromSource <= distanceThreshold){
                            q.emplace(distanceFromSource, neighbor);
                        }
                    }
                }
            }
            return visited.size()-1;
        };

        int minNum = n;
        int res=-1;

        for(int source=0;source<n;source++){
            int neighbours = getNeighbour(source);
            if(neighbours<=minNum){
                minNum = neighbours;
                res = source;
            }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}