#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void del(ListNode* &head, ListNode* ptr){
        if(ptr->next==NULL){
            head->next=NULL;
        }else{
            head->next=ptr->next;
        }
        delete ptr;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* current = head;
        while(current->next!=NULL && current->next->next!=NULL){
            ListNode* ptr=current->next;
            if(current->val==ptr->val){
                del(current,ptr);
            }else{
                current=current->next;
            }
        }

        //last two nodes
        if(current->next !=NULL && current->val==current->next->val){
            del(current, current->next);
        }

        return head;
    }
};

int main()
{
    
    return 0;
}