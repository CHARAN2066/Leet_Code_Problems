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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        if(n==0)
        return NULL;
        int a=k%n;
        n-=a;
        temp=head;
        ListNode* ans=NULL;
        while(temp!=NULL)
        {
            n--;
            if(n==0){
                ans=temp;
                break;
            }
            temp=temp->next;
        }
        if(ans->next==NULL)
        return head;
        else{
            temp=ans->next;
            ListNode* res=ans->next;
            ans->next=NULL;
            while(temp!=NULL){
                if(temp->next==NULL)
                {
                    // cout<<temp->val<<endl;
                    temp->next=head;
                    break;
                }
                temp=temp->next;
            }
            return res;
        }
        return NULL;
    }
};