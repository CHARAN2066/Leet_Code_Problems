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
    //void delete_node(ListNode* )
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        int fre[1000000]={0};
        int n=nums.size();
        vector<int> ans;
        if(head==NULL)
        return NULL;
        for(int i=0;i<n;i++)
        {
            fre[nums[i]]++;
        }
        ListNode* temp=head;
        while(temp!=0)
        {
            if(fre[temp->val]==0)
            ans.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=0;
        int s=ans.size();
        while(temp!=0)
        {
            temp->val=ans[i];
            if(i==s-1)
            {
                temp->next=NULL;
                break;
            }
             i++;
            temp=temp->next;
        }

        return head;
    }
};