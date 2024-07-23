#include<iostream>
#include<vector> 
#include<climits>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        vector<int> index;

        ListNode* prev = head;
        ListNode* curr = head->next;
        if(curr==nullptr) return ans;
        ListNode* nextN = curr->next;
        if(nextN==nullptr) return ans;

        int i=1;
        while(nextN!=nullptr){
            if((prev->val<curr->val && nextN->val<curr->val)||(prev->val>curr->val && nextN->val>curr->val)){
                index.push_back(i);
            }
            prev=prev->next;
            curr=curr->next;
            nextN=nextN->next;
            i++;
        }

        if(index.size()<2) return ans;

        int minDist = INT_MAX;
        for (size_t i = 1; i < index.size(); ++i) {
            minDist = min(minDist, index[i]-index[i-1]);
        }

        ans[0]=minDist;
        ans[1]=index.back()-index.front();

        return ans;
    }
};

int main()
{
    
    return 0;
}