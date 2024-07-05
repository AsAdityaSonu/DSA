#include<iostream>
using namespace std;

// Approach 1: Time complexity: O(n)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* dummy=ans;

        head=head->next;
        int sum=0;
        while(head!=nullptr){
            if(head->val==0){
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                sum=0;
            }else{
                sum+=head->val;
            }

            head=head->next;
        }
        return ans->next;
    }
};

// Approach 2: better than 92.73% 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* nextSum = modify;

        while(nextSum!=nullptr){
            int sum =0;
            while(nextSum->val!=0){
                sum+=nextSum->val;
                nextSum = nextSum->next;
            }

            modify->val = sum;
            nextSum = nextSum->next;
            modify->next=nextSum;
            modify=modify->next;
        }

        return head->next;
    }
};

int main()
{
    
    return 0;
}