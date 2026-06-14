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
    int pairSum(ListNode* head) {
        int c=0,n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            c++;
            if(c==((n/2)+1)) break;
            temp=temp->next;
        }
        ListNode* i=NULL,*j=temp,*k=NULL;
        if(temp->next!=NULL)
        k=temp->next;
        while(j!=NULL){
            j->next=i;
            i=j;
            j=k;
            if(k!=NULL)
            k=k->next;
            else
            break;
        }
        // cout<<i->val<<endl;
        int ans=0;
        temp=i;
        ListNode* temp2=head;
        while(temp!=NULL&&temp2!=NULL){
            ans=max(ans,(temp->val+temp2->val));
            temp=temp->next;
            temp2=temp2->next;
        }
        return ans;
    }
};