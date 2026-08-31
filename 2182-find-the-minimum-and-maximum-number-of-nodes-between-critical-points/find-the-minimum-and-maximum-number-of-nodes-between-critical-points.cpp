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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> ans;
        vector<int> res;
        ListNode *temp=head->next;
        ListNode *pre=head;
        int p=1;
        while(temp->next!=NULL)
        {
            p++;
            if((pre->val<temp->val&&temp->next->val<temp->val)||(pre->val>temp->val&&     temp->next->val>temp->val))
            ans.push_back(p);
            pre=temp;
            temp=temp->next;
        }
        int m=100000,n=ans.size();
        if((n==0)||(n==1))
        {
        res.push_back(-1);
        res.push_back(-1);
        return res;
        }
        else
        {
           
            for(int i=0;i<n-1;i++)
            {
                m=min(m,(ans[i+1]-ans[i]));
            }
            res.push_back(m);
            res.push_back(ans[n-1]-ans[0]);
            return res;
        }
    }
};