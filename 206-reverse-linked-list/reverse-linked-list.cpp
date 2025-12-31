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
    ListNode* reverseList(ListNode* head) {
        ListNode *i=NULL,*k=NULL,*j=head;
        if(head==NULL)
        return NULL;
        if(head->next==NULL)
        return head;
        // if(head->next->next)
        if(head->next!=NULL)
        k=head->next;
        while(j!=NULL){
            j->next=i;
            i=j;
            j=k;
            if(k!=NULL)
            k=k->next;
            else
            break;
            // break;
        }
        // i->next=NULL;
        return i;

    }
};