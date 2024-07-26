#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Approach 1: Using queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size()>1){
            for(int i=1;i<k && q.size()>1;i++){
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
            q.pop();
        }

        return q.front();
    }
};

// Approach 2: Using vector - Better than 100%
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }

        int index=0;
        while(v.size()>1){
            index=(index+k-1)%v.size();
            v.erase(v.begin()+index);
        }

        return v[0];
    }
};

int main()
{
    
    return 0;
}